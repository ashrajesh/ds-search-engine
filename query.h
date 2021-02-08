//
// Created by Ashwi on 11/25/2020.
//

#ifndef SEARCH_ENGINE_ASHWIN_RAJESH_QUERY_H
#define SEARCH_ENGINE_ASHWIN_RAJESH_QUERY_H
#include <iostream>
#include "AVLSuperRoot.h"
#include "hash_table.h"
#include <map>

using namespace std;

void choose_article(vector<string>& final_ids);
void ranker(map<string, int>& results);
void get_query(AVLSuperRoot& tree_ref, hash_table<string,vector<string>>& authors);
void process_query(AVLSuperRoot& tree_ref, string& input, hash_table<string,vector<string>>& authors);

#endif //SEARCH_ENGINE_ASHWIN_RAJESH_QUERY_H
