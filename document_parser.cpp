//
// Created by Ashwi on 11/14/2020.
//

#include "document_parser.h"
#include <sstream>
#include "hash_table.h"
#include "word.h"
#include "porter2_stemmer.h"
#include <fstream>

using namespace std;
using namespace simdjson;

void parse_json(string json_path, unordered_map<string, word*>& wordie, hash_table<string,vector<string>>& authors, set<string>& stop_words) { //
    dom::parser parser;
    dom::object data;
    auto error = parser.load(json_path).get(data);
    string_view id, title, body_of_text;
    dom::object metadata_sim;
    dom::array authArray;

    if((error = data["paper_id"].get(id))){cerr<<error<<endl;exit(1);}
    if((error = data["metadata"].get(metadata_sim))){cerr<<error<<endl;exit(2);}
    if((error = metadata_sim["title"].get(title))){cerr<<error<<endl;exit(3);}
    if((error = metadata_sim["authors"].get(authArray))){cerr<<error<<endl;exit(6);}

    string fast_ID {id};
    string fast_Title {title};

    for(dom::object names : authArray){
        string full_name;
        string_view first_name, last_name;
///     Below for using full name implementation:
//      if((error = names["first"].get(first_name))){cerr<<error<<endl;exit(4);}
//      string firsty {first_name};
//      full_name += firsty;
//      full_name += " ";
        if((error = names["last"].get(last_name))){cerr<<error<<endl;exit(5);}
        string lasty {last_name};
        full_name += lasty;
        vector<string> to_push;
        to_push.push_back(fast_ID);
        vector<string> manipulated;
        bool author_on_table = false;
        if(authors.get(full_name, manipulated)){
            manipulated.push_back(fast_ID);
            authors.insert(full_name, manipulated);
            author_on_table = true;
        }
        else if(full_name != ""){
            authors.insert(full_name, to_push);
        }
    }

    dom::array body_text;
    if((error = data["body_text"].get(body_text))){cerr<<error<<endl;exit(8);}
    string temp_string;
    for(dom::object bodies : body_text){
        if((error = bodies["text"].get(body_of_text))){cerr<<error<<endl;exit(7);}
        for(int i = 0; i < body_of_text.size(); i++){
            if((body_of_text[i]>='a'&&body_of_text[i]<='z')){
                temp_string += body_of_text[i];
            }
            else if((body_of_text[i]>='A'&&body_of_text[i]<='Z')){ // || isdigit(body_of_text[i])
                temp_string += tolower(body_of_text[i]);
            }
            else{
                const bool is_in = stop_words.find(temp_string) != stop_words.end();
                Porter2Stemmer::stem(temp_string);
                if(temp_string.size()>2 && is_in==false) { // make sure we only take in words with more than 2 characters and they are not stopwords.
                    unordered_map<string, word *>::iterator iterate = wordie.find(temp_string);     // initialize iterator to find out whether temp_string exists in map
                    if (iterate != wordie.end()) {      // else if word does exist on map
                        iterate->second->add_instance(fast_ID,fast_Title); // add another instance of this word for current errorument
                    }
                    else {        // if word doesn't exist on map
                        wordie[temp_string] = new word(temp_string, fast_ID, fast_Title);       // add new word object into the map
                    }
                }
                temp_string = "";       // reset temp_string
            }
        }
    }
}

void load_index(AVLSuperRoot& return_me){
    //format for output: word num_instances freq ID freq ID freq ID...
    ifstream persistent_index;
    persistent_index.open("persistent_index.txt");
    char* temp = new char[1000000];
    int counter = 0;
    while(persistent_index.getline(temp, 999999, '\n')) {
            stringstream streamer(temp);
            vector<string> elements;
            while(streamer.getline(temp, 9999, ' ')){
                string push_me = temp;
                elements.push_back(push_me);
            }
            word *new_word = new word(elements[0]);
            int instances = stoi(elements[1]);
            for(int i = 2; i < 2*instances+2; i+=2){
                new_word->parse_instance(stoi(elements[i]), elements[i+1]);
            }
            return_me.insert(new_word);
            counter++;
    }
    persistent_index.close();
    delete[] temp;
}

void persistent_stats(int& total_words, int& total_authors, int& num_articles, vector<string>& popular_words, vector<int>& popular_freq){
    int counter = 0;
    ifstream stats_input;
    stats_input.open("stats_file.txt");
    char* tempy = new char[50];
    while(stats_input.getline(tempy,49,'\n')){
        string curr_element = tempy;
        if(counter == 0){
            total_words = stoi(curr_element);
        }
        else if(counter == 1){
            total_authors = stoi(curr_element);
        }
        else if (counter == 2){
            num_articles = stoi(curr_element);
        }
        else{
            string push_word;
            string temp_freq;
            bool word_over = false;
            for(int i = 0; i < curr_element.size(); i++){
                if(word_over == false) {
                    if (curr_element[i] != ',') {
                        push_word += curr_element[i];
                    }
                    else{
                        word_over = true;
                    }
                }
                else{
                    temp_freq += curr_element[i];
                }
            }
            popular_words.push_back(push_word);
            popular_freq.push_back(stoi(temp_freq));
        }
        counter++;
    }
    delete[] tempy;
}


void display_articles(vector<string>& doc_ID){
    if(doc_ID.size() == 0){
        cout << endl << "Sorry, we couldn't find any documents matching your search criteria :(" << endl << endl;
    }
    else {
        cout << endl;
        for (int i = 0; i < doc_ID.size(); i++) {
            cout << "Article " << i+1 << ":" << endl;
            ifstream article;
            string article_path = "C:/Users/Ashwi/OneDrive/Documents/Downloads/cs2341_data/";
            article_path += doc_ID[i];
            article_path += ".json";
            dom::parser parser;
            dom::object data;
            auto error = parser.load(article_path).get(data);
            string_view id, title;
            dom::object metadata_sim;

            if ((error = data["paper_id"].get(id))) {cerr << error << endl;exit(1);}
            if ((error = data["metadata"].get(metadata_sim))) {cerr << error << endl;exit(2);}
            if ((error = metadata_sim["title"].get(title))) {cerr << error << endl;exit(3);}
            cout << title;
            if(title == ""){
                cout << "N/A   Research Article Has No Title.";
            }
            cout << endl << endl;
        }
    }
}

void display_preview(string doc_ID){
        cout << endl;
            ifstream article;
            string article_path = "C:/Users/Ashwi/OneDrive/Documents/Downloads/cs2341_data/";
            article_path += doc_ID;
            article_path += ".json";
            dom::parser parser;
            dom::object data;
            auto error = parser.load(article_path).get(data);
            string_view id, title, body_of_text;
            dom::object metadata_sim;

            if ((error = data["paper_id"].get(id))) {cerr << error << endl;exit(1);}
            if ((error = data["metadata"].get(metadata_sim))) {cerr << error << endl;exit(2);}
            if ((error = metadata_sim["title"].get(title))) {cerr << error << endl;exit(3);}
            cout << "Title: " << title;
            if(title == ""){
                cout << "N/A   Research Article Has No Title.";
            }
            cout << endl;
            cout << "Research Paper ID: " << id << endl;
            dom::array authArray;
             if((error = metadata_sim["authors"].get(authArray))){cerr<<error<<endl;exit(6);}
            cout << "Authors: ";
             for(dom::object names : authArray){
                string_view first_name, last_name;
                if((error = names["first"].get(first_name))){cerr<<error<<endl;exit(4);}
                if((error = names["last"].get(last_name))){cerr<<error<<endl;exit(4);}
                cout << first_name << " " << last_name << "  ";
            }

            ifstream metadata;
            metadata.open("C:/Users/Ashwi/OneDrive/Documents/GitHub/search-engine-ashwin-rajesh/metadata-cs2341.csv");
            //char* tempy = new char[1000000]; //10000
            //char tempy [1000000];
            while(true){ //9999
                char tempy [1000000];
                if(!metadata.getline(tempy,999999,'\n')){
                    break;
                }
                string full_csv = tempy;
                string curr_id;
                int end_index;
                for(int i = 0; i < full_csv.size(); i++){
                    if(full_csv[i] != ',') {
                        curr_id += full_csv[i];
                    }
                    else{
                        end_index = i;
                        break;
                    }
                }
                if(doc_ID == curr_id){
                    //cout << endl << endl << "FOUNDEM" << endl;
                    int new_end_index;
                    string date;
                    for(int x = end_index+1; x <full_csv.size(); x++){
                        if(full_csv[x] != ','){
                            date += full_csv[x];
                        }
                        else{
                            new_end_index = x;
                            break;
                        }
                    }
                    cout << endl << "Date of Publication: " << date;
                    if(date == ""){
                        cout << "N/A";
                    }
                    cout << endl;

                    string publisher;
                    for(int y = new_end_index+1; y < full_csv.size(); y++){
                        if(full_csv[y] != ','){
                            publisher += full_csv[y];
                        }
                        else{
                            break;
                        }
                    }
                    cout << "Publishing Journal: " << publisher;
                    if(publisher == ""){
                        cout << "N/A";
                    }
                }
            }
            metadata.close();


            cout << endl << "Preview:" << endl;

            dom::array abstract_text;
            if ((error = data["abstract"].get(abstract_text))) {cerr << error << endl;exit(8);}
            string total_text;
            for (dom::object bodies : abstract_text) {
                if ((error = bodies["text"].get(body_of_text))) {cerr << error << endl;exit(7);}
                //cout << body_of_text << endl;
                string curr_text {body_of_text};
                total_text += curr_text;
            }
            if(total_text == ""){
                cout << "ABSTRACT NOT AVAILABLE FOR THIS ARTICLE :(" << endl;
                cout << "First 300 words of paper:" << endl;
                string_view body_of_text;
                dom::array body_text;
                if((error = data["body_text"].get(body_text))){cerr<<error<<endl;exit(8);}
                string temp_string;
                int max_count = 0;
                for(dom::object bodies : body_text) {
                    if ((error = bodies["text"].get(body_of_text))) {cerr << error << endl;exit(7);}
                    string bodyoftext {body_of_text};
                    for (int i = 0; i < bodyoftext.size(); i++) {
                        if (bodyoftext[i] != ' ') {
                            temp_string += body_of_text[i];
                        }
                        else{
                            cout << temp_string << " ";
                            temp_string = "";
                            max_count += 1;
                            if (max_count >= 300){
                                cout << "here";
                                break;
                            }
                        }
                    }
                    if (max_count >= 300){
                        cout << "..." << endl;
                        break;
                    }
                }
            }
            total_text += "...";
            string temp_word;
            int max_words = 0;
            for(int i = 0; i < total_text.size()+1; i++){
                if(max_words >= 300){cout<<"...";break;}
                if(total_text[i] != ' ' && total_text[i] != '\n'){
                    temp_word += total_text[i];
                }
                else{
                    cout << temp_word << " ";
                    temp_word = "";
                    max_words++;
                }
            }

            cout << endl;
}