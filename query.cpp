//
// Created by Ashwi on 11/25/2020.
//

#include "query.h"
#include <vector>
#include "word.h"
#include "document_parser.h"
#include "porter2_stemmer.h"

void choose_article(vector<string>& final_ids){
    if(final_ids.size() != 0) {         // if there are no results to choose from, don't do anything!
        while (1) {                     // user will have to select to break from this loop, or else it will go on
            int selected_num;           // stores the desired article number to select
            cout << endl << "Select an Article Number to Preview (0 to exit): ";
            cin >> selected_num;
            if (selected_num == 0) {    // if 0, user has opted to exit search query
                break;
            } else {
                if (selected_num <= final_ids.size()) {     // ensure that option is valid
                    display_preview(final_ids[selected_num - 1]);     // call display preview function from document_parser.cpp, displays title, id, authors, date, publisher and first 300 words of abstract (or body text)
                } else {
                    cout << endl << "Please enter a valid number!" << endl;
                }
            }
        }
        cout << endl;
    }
}

void ranker(map<string,int>& results){      // takes the list of final ids and corresponding "relavancy" weightage, and displays top 15 results to choose from
    vector<string> final_ids;           // will store the ids of the top 15 articles
    int counter = 0;
    int const_size = results.size();    // size of the map we parse through
    while(counter < 15 && counter < const_size){
        string best_ID;
        int max = 0;
        for(auto it = results.begin(); it != results.end(); ++it){  // sets best_ID and max to the top word and top weightage in the map
            if(it->second > max){
                best_ID = it->first;
                max = it->second;
            }
        }
        final_ids.push_back(best_ID);               // push result id to final id list
        results.erase(best_ID);                     // remove this result so that for the next iteration, we find the next highest result
        counter++;
    }
    display_articles(final_ids);        // call display_articles form document_parser.cpp
    choose_article(final_ids);          // call choose_article to get more info on individual articles (from top 15)
}

void author_push(hash_table<string,vector<string>>& authors, map<string,int>& results, string desired_author){
    vector<string> var;
    vector<string> author_docs;

    for(int i = 0; i < authors.keys.size(); i++){
        string auth_compare;
        for(int f = 0; f < authors.keys.at(i).size(); f++){
            auth_compare += tolower(authors.keys.at(i)[f]);
        }
        authors.get(authors.keys.at(i), var);
        if(desired_author == auth_compare){
            for(int w = 0; w < var.size(); w++) {
                //cout << var[w];
                author_docs.push_back(var[w]);
            }
        }
    }

    for(auto it = results.begin(); it != results.end(); ++it) {
        bool doc_has_desired_author = false;
        for(int i = 0; i < author_docs.size(); i++){
            if(it->first == author_docs[i]){
                doc_has_desired_author = true;
            }
        }
        if(doc_has_desired_author == false){
            results.erase(it->first);
        }
    }
}

void process_query(AVLSuperRoot& tree_ref, string& input, hash_table<string,vector<string>>& authors){
    vector<string> search_terms;    // max of 5 search terms
    string temp_word;

    for(int i = 0; i < input.size()+1; i++){        // we do +1 to size to account for the last char (null) which will trigger else statement for final word
        if((input[i] >= 'a' && input[i] <= 'z')) {
            temp_word += input[i];
        }
        else if ((input[i] >= 'A' && input[i] <= 'Z')){
            temp_word += tolower(input[i]);
        }
        else{
            if(temp_word.size()>1){     // only consider words greater than 2 characters
                Porter2Stemmer::stem(temp_word);
                search_terms.push_back(temp_word);  // push to vector
                temp_word = ""; // reset the word
            }
        }
    }

    map<string, int> results;   // initialize map that will hold our potential results (we only take top 15)

    if(search_terms[0] == "and"){       // since "and" / "or" will always be the first ones (if they are to be included)
        int num =  1;
        for(int z = 1; z < search_terms.size(); z++){
            if(search_terms[z] == "not"){                   // "not" can appear at any time
                z++;
                word *not_term = new word(search_terms[z]);   // create word object for string that comes after "not"
                tree_ref.search_three_not(not_term, results);   // search_three_not -> push_stuff_not will remove entries that have word in it
                //break;          // don't break because author could be last thing in input

            }
            else if(search_terms[z] == "author"){
                author_push(authors, results, search_terms[z+1]);                // WAITING ON HASH TABLE FROM PARTNER
                break;          // stated in handout that author will be the last thing inputted by user
            }
            /// figure out stemming stuff here!!
            else{
            word *term = new word(search_terms[z]);         // new word object
            tree_ref.search_three_and(term, results, num);  // search_three_and -> push_stuff_and will push all docs for first string, for second+ string (num != 1) will remove entries if not exist for word and increase frequency for common words
            num++;
            }
        }
    }
    else if(search_terms[0] == "or"){
        for(int z = 1; z < search_terms.size(); z++){
            if(search_terms[z] == "not"){
                z++;
                word *not_term = new word(search_terms[z]);
                tree_ref.search_three_not(not_term, results);
                //break;
            }
            else if(search_terms[z] == "author"){
                author_push(authors, results, search_terms[z+1]);
                break;      // stated in handout that author will be the last thing inputted by user
            }
            else {
                word *term = new word(search_terms[z]);
                tree_ref.search_three_or(term, results);
            }
        }
    }
    else{       // if AND / OR not stated, just treat the input string(s) as or
        for(int z = 0; z < search_terms.size(); z++){
            if(search_terms[z] == "not"){
                z++;
                word *not_term = new word(search_terms[z]);
                tree_ref.search_three_not(not_term, results);
                //break;
            }
            else if(search_terms[z] == "author"){
                author_push(authors, results, search_terms[z+1]);
                break;          // stated in handout that author will be the last thing inputted by user
            }
            else {
                word *term = new word(search_terms[z]);
                tree_ref.search_three_or(term, results);
            }
        }
    }
    ranker(results);
}

void get_query(AVLSuperRoot& tree_ref, hash_table<string,vector<string>>& authors){
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    string input;
    cout << endl << "Please enter search query: " << endl;
    //cin >> input;
    getline(cin, input);        // cin entire line and store in input
    process_query(tree_ref, input, authors); // function that processes the input string
}