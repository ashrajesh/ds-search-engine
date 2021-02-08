//
// Created by Ashwi on 12/1/2020.
//

#ifndef SEARCH_ENGINE_ASHWIN_RAJESH_USER_INTERFACE_H
#define SEARCH_ENGINE_ASHWIN_RAJESH_USER_INTERFACE_H

#include "document_parser.h"
#include "hash_table.h"
#include "word.h"
#include <string>
#include <iostream>
#include<dirent.h>
#include "AVLSuperRoot.h"
#include "query.h"
#include "hashread.h"
#include <set>

using namespace std;

void  welcome(AVLSuperRoot& curr_tree, unordered_map<string, word *>& listy, hash_table<string, vector<string>>& authors, set<string>& stop_words);
void populate_stopwords(set<string>& stop_words);



#endif //SEARCH_ENGINE_ASHWIN_RAJESH_USER_INTERFACE_H
