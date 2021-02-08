//
// Created by Ashwi on 11/15/2020.
//

#include "word.h"
#include <fstream>

using namespace std;

word::word(){
    data = "null";
    total_frequency = 0;
}
word::word(const word& x){
    data = x.data;
    frequency = x.frequency;
    id = x.id;
    title = x.title;
    total_frequency = x.total_frequency;
}
word::word(string text){
    data = text;
    total_frequency = 1;
}

word::word(string &temp_data, string &temp_id, string &temp_title){
    data = temp_data;
    frequency.push_back(1);
    id.push_back(temp_id);
    title.push_back(temp_title);
    total_frequency = 1;
}

int word::get_total_freq() {
    return total_frequency;
}

int word::get_char(){
    //char r = this->data.at(0);
    return (int)this->data[0];
}

void word::parse_instance(int temp_freq, string temp_id) {
    frequency.push_back(temp_freq);
    id.push_back(temp_id);
    total_frequency += temp_freq;
}

void word::add_freq(){
    frequency[frequency.size()-1]++;
}

void word::push_word(string temp_data, int temp_frequency, string &temp_id, string &temp_title){
    data = temp_data;
    frequency.push_back(temp_frequency);
    id.push_back(temp_id);
    title.push_back(temp_title);
}

void word::print_word(){
    for(int i = 0; i < id.size(); i++){
        cout << data << " " << frequency[i] << " " << id[i] << endl;
    }
    //cout << data << " " << frequency.at(0) << " " << id.at(0) << endl;
}

void word::push_stuff(vector<pair<string, int>>& push_me){
    for(int i = 0; i < id.size(); i++){
        push_me.push_back(make_pair(id[i], frequency[i]));
    }
}

void word::push_stuff_and(map<string, int> &push_me, int num) { // and will add all new (only for first) and similar docs, delete all others
    if(num == 1) {
        for (int i = 0; i < id.size(); i++){
            push_me.insert({id[i], frequency[i]});
        }
    }
    else{
        for(auto x: push_me){
            bool exists = false;
            for(int j = 0; j < id.size(); j++){
                if(x.first == id[j]){
                    x.second += frequency[j];
                    exists = true;
                }
            }
            if(exists == false){
                push_me.erase(x.first);
            }
        }
    }
}

void word::push_stuff_or(map<string, int> &push_me) {       // or will add all similar docs (while appending to frequency too for relevancy purposes) and add any new ones too
    for(int i = 0; i < id.size(); i++){
        map<string,int>::iterator iterate = push_me.find(id[i]);
        if(iterate != push_me.end()){
            iterate->second += frequency[i];
        }
        else{
            push_me.insert({id[i], frequency[i]});
        }
    }
}

void word::push_stuff_not(map<string, int> &push_me) {  // not will delete any documentid from the map with the word in it
    for(int i = 0; i < id.size(); i++){
        map<string,int>::iterator iterate = push_me.find(id[i]);
        if(iterate != push_me.end()){
            push_me.erase(iterate->first);
        }
    }
}



string word::get_text() {
    return data;
}

int word::get_size(){
    return id.size();
}

string word::get_latest_ID() {
    return id[id.size()-1];
}

void word::add_instance(string &temp_id, string &temp_title){
    if(id[id.size()-1] == temp_id){
        frequency[frequency.size()-1]++;
        total_frequency++;
    }
    else {
        frequency.push_back(1);
        id.push_back(temp_id);
        title.push_back(temp_title);
        total_frequency++;
    }
}

word& word::operator+= (word& word_ref){
    //word_ref.add_instance(this->frequency[0], this->id[0], this->title[0]);
    this->add_instance(word_ref.id[0], word_ref.title[0]);
    //word_ref.print_word();
    return *this;
}

bool word::operator== (word& word_ref){
    if (this->data == word_ref.data){
        //this->print_word();
        return true;
    }
    else{
        return false;
    }
}


bool word::operator> (word& word_ref){
    return this->data > word_ref.data;
}
bool word::operator< (word& word_ref){
    return this->data < word_ref.data;
}

ostream& operator << (ostream& out, word& word_ref){
    out << word_ref.data << " " << word_ref.id.size();
    for(int i = 0; i < word_ref.id.size(); i++){
        out <<" " << word_ref.frequency[i] << " " << word_ref.id[i];
    }
    out << endl;
    return out;
}