//
// Created by Ashwi on 11/14/2020.
//

#include "document_parser.h"
#include "hash_table.h"
#include "word.h"
#include <string>
#include <iostream>
#include "AVLSuperRoot.h"
#include <set>
#include "User_Interface.h"

using namespace std;

int main(int argc, char** argv) {
    hash_table<string, vector<string>> authors;     // hash table will store the authors last name (as a key) and a vector of document IDs in which the author appears in (as a value)
    unordered_map<string, word *> listy;            // we use a map to store and "modify" our word objects before insertion into AVL tree
    AVLSuperRoot better_tree;                       // initialization of super tree (contains many templated avl sub trees)
    set<string> stop_words;                         // we use a set of keys to store all potential stopwords / noise

    cout<< endl<< endl << endl<< "           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl<< "              Welcome to the Covid-19 Search Engine!" << endl<< "           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl << endl<<endl;        // welcome message upon program start

    populate_stopwords(stop_words);                                 // function reads stopwords.txt an populates set with string keys
    welcome(better_tree, listy, authors, stop_words);   // function handles User Interface

    return 0;                                       // end program
}