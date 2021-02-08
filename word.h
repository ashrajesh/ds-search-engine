//
// Created by Ashwi on 11/15/2020.
//

#ifndef SEARCH_ENGINE_ASHWIN_RAJESH_WORD_H
#define SEARCH_ENGINE_ASHWIN_RAJESH_WORD_H

#include <vector>
#include <iostream>
#include <map>
#include "hash_table.h"

using namespace std;

class word {
private:
    string data;    // stores the actual word
    vector<int> frequency; // parallel vector that stores frequency of word in each document it appears in
    vector<string> id; // parallel vector that stores all of the json ID's of each document the word appears in
    vector<string> title; // parallel vector that stores all of the titles of each paper the word appears in
    int total_frequency;

public:
    word();
    word(const word& x); // we never use this
    word(string &temp_data, string &temp_id, string &temp_title);
    ~word(){};
    word(string text);

    void parse_instance(int temp_freq, string temp_id);
    void add_freq();
    void push_word(string temp_data, int temp_frequency, string &temp_id, string &temp_title); // adding properties to newly created word object
    void print_word(); // prints frequency and ID for all documents word is in
    void push_stuff(vector<pair<string, int>>& push_me);
    void push_stuff_and(map<string,int>& push_me, int num);
    void push_stuff_or(map<string,int>& push_me);
    void push_stuff_not(map<string,int>& push_me);
    void add_instance(string &temp_id, string &temp_title); // adding to parallel vectors once word appears in more than one JSON

    int get_char();
    int get_total_freq();

    string get_text();
    int get_size(); // tells us how many documents word appears in
    string get_latest_ID();

    bool operator== (word& word_ref);   // if this returns true, we add_instance() to this word object
    bool operator> (word& word_ref);
    bool operator< (word& word_ref);

    word& operator+= (word& word_ref);

    friend ostream& operator << (ostream& out, word& word_ref);
};


#endif //SEARCH_ENGINE_ASHWIN_RAJESH_WORD_H
