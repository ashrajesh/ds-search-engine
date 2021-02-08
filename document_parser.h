//
// Created by Ashwi on 11/14/2020.
//

#ifndef UNTITLED7_DOCUMENT_PARSER_H
#define UNTITLED7_DOCUMENT_PARSER_H

#include <iostream>
#include <unordered_map>
#include "word.h"
#include "hash_table.h"
#include <string>
#include "simdjson.h"
#include "AVLSuperRoot.h"
#include <set>
using namespace simdjson;
using namespace std;

void parse_json(string json_path, unordered_map<string, word*>& wordy, hash_table<string,vector<string>>& authors, set<string>& stop_words);
void load_index(AVLSuperRoot& return_me);
void display_articles(vector<string>& doc_ID);
void display_preview(string doc_ID);
void persistent_stats(int& total_words, int& total_authors, int& num_articles, vector<string>& popular_words, vector<int>& popular_freq);


#endif //UNTITLED7_DOCUMENT_PARSER_H
