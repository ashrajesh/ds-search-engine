//
// Created by Ashwi on 12/1/2020.
//

#include "User_Interface.h"
#include <iomanip>

void  welcome(AVLSuperRoot& curr_tree, unordered_map<string, word *>& listy, hash_table<string, vector<string>>& authors, set<string>& stop_words){
    vector<string> popular_words;           // used for search-engine stats, stores 50 words with most appearances
    vector<int> popular_freq;               // used for search-engine stats, stores the corresponding frequency of the top 50 words
    int total_words = 0;                    // used for search-engine stats, total number of unique words (total # nodes in avl tree) parsed
    int total_authors = 0;                  // used for search-engine stats, total number of (somewhat unique [author lastname]) authors from parsed files
    int num_articles = 0;                   // used for search-engine stats, total number of JSONs parsed
    bool t = true;              // used in option #6 to break out of while loop:
    while(t){
        cout<< "                   What would you like to do?" <<endl;              // line 16-25 prints out the options table for Users to choose from
        cout << "            _________________________________________" << endl;
        cout << "           |  1. Search Database                     |" << endl;
        cout << "           |  2. Load Index From Disk                |" << endl;
        cout << "           |  3. Parse & Populate Database / Index   |" << endl;
        cout << "           |  4. Clear Index                         |" << endl;
        cout << "           |  5. Save Index to Disk                  |" << endl;
        cout << "           |  6. Quit                                |" << endl;
        cout << "            _________________________________________" << endl;
        cout << endl << "  Select an option: ";
        int option;        // will store the option chosen by User
        try {
            cin >> option;      // take input from user and store in option
            if(option > 7 || option <1){    // ensure that the option input is a valid number
                cout << endl << "Invalid selection, please enter valid option!" << endl << endl;
                welcome(curr_tree, listy, authors, stop_words); // ask user to select option again
            }
            if(cin.fail()){
                throw "error";
            }
        }
        catch (char* error){    // if cin fails (input not integer)
            cout << "Invalid Selection" << endl;
            welcome(curr_tree, listy, authors, stop_words); // allow user to re-enter option
        }
        if(option == 1){                                        // if user selects option #1
            get_query(curr_tree, authors);              // call get_query function from query.cpp (processes, handles all queries and searches a user may have)
        }
        if(option == 2){                                        // if user selects option #2
            cout << endl << "Loading Index..." << endl;         // this function loads our indexes with data on "disk" (alternative to re-parsing files)
            load_index(curr_tree);                          // call load_index from document_parser.cpp (populates the AVL super tree with word objects from persistent index)
            cout << "AVL Tree Loaded." << endl;
            hashread load_hash;                                 // create hashread object (to access functions for next line)
            load_hash.readin(authors);                      //  calls readin function from hashread.cpp (populates the hash table with authors, document IDs from persistent index)
            cout << "Hash Table Loaded." << endl;
            persistent_stats(total_words,total_authors,num_articles,popular_words,popular_freq);    // persistent_stats function from document_parser.cpp stores the search engine stats to the variables passed into it
            cout << "Index Loaded." << endl << endl;
        }
        if(option == 3)                                         // if user selects option #3
        {
            /// Parsing JSON Files:
            cout << endl << "Loading Index..." << endl;
            string directory_path = "C:/Users/Ashwi/OneDrive/Documents/Downloads/cs2341_data";  // this is the path to the directory of the 12k JSONs on my computer, replace with location of documents on your own computer.
            dirent *entry;              // taken from dirent library examples online (file/folder/directory handling)
            DIR *dp;                    // taken from dirent library examples online (file/folder/directory handling)
            dp = ::opendir(directory_path.c_str());     // taken from dirent library examples online (file/folder/directory handling)
            int counter = 0; // counter used to keep track of how many files have been parsed
            cout << "Parsing JSON Files..." << endl;
            while ((entry = ::readdir(dp))) {   // taken from dirent library examples online (file/folder/directory handling) this loop goes through each file in directory
                if (strlen(entry->d_name) > 2 && entry->d_name[0] != '.') {   // taken from dirent library examples online (file/folder/directory handling) checks whether file name is valid (can it be parsed?)
                    //cout << counter << endl;          // uncomment this line to view progression of parsing
                    parse_json(directory_path + "/" + entry->d_name, listy, authors, stop_words);   // calls parse_json function from document_parser.cpp
                }
                counter++; // increment counter after file parsed
            }
            ::closedir(dp);
            num_articles = counter;                                 // set num_articles to the counter
            int list_size = listy.size();                           // list size represents the total number of unique words parsed in
            cout << "Total Number of Words: " << list_size << endl;
            cout << "Total Number of Authors: " << authors.keys.size() << endl;
            total_words = list_size;                                // total words can be represented by list size ^^^^^^^
            total_authors = authors.keys.size();                    // set total number of "unique" authors to the number of keys in hash table

            /// Insert Words to AVL tree
            //int tree_count = 1;
            cout << "Inserting Words into AVL Tree..." << endl;
            for (auto y : listy) {                              // insert every word stored in the unordered map into the AVL Tree
                curr_tree.insert(y.second);
                //tree_count++;
                //cout << tree_count << " of " << list_size << " words parsed" << endl; /// uncomment these lines to recieve information about parsing progress
            }
            cout << "Done inserting." << endl << endl;
            map<string,int> top_fifty;                              // this map will hold the word text, word frequency for all words in listy
            for (auto z : listy){                                   // for loop populates map
                top_fifty.insert(make_pair(z.second->get_text(),z.second->get_total_freq()));
            }
            int count_top = 0;
            while(count_top < 50){                                  // loop finds top fifty words and pushes to the popular vectors
                string best_Top;                                    // will store the text of the current popular word
                int max = 0;                                        // will store the frequency of current popular word
                for(auto it = top_fifty.begin(); it != top_fifty.end(); ++it){  // iterate through every element in map
                    if(it->second > max){                               // if current element, is greater than the current maximum recorded word
                        best_Top = it->first;                           // switch current best word to this word
                        max = it->second;                               // ^^^^ and it's corresponding frequency
                    }
                }
                popular_words.push_back(best_Top);                      // push current popular word to vector
                popular_freq.push_back(max);                        // push current top frequency to vector
                top_fifty.erase(best_Top);                          // erase from map, so during the next search we don't push the same word again
                count_top++;
            }
        }

        if(option == 4){
            /// Makes all of the following text files empty:
            cout << endl<< "Clearing Index..." << endl;
            ofstream tree;
            tree.open("persistent_index.txt", ofstream::out|ofstream::trunc);
            tree.close();
            ofstream table;
            table.open("authors.txt", ofstream::out|ofstream::trunc);
            table.close();
            ofstream stats;
            stats.open("stats_file.txt", ofstream::out|ofstream::trunc);
            stats.close();
            cout << "Indexes Cleared." << endl<<endl;
        }

        if(option == 5){
            cout << endl << endl << "Saving Indexes to Disk..." << endl;
            curr_tree.load_order();   // load_order from AVLSuperRoot.h calls .level_order from tree_two.h for each subree and provides a more efficient order for outputting to .txt file such that it is easier to read in
            cout << "AVL Tree Saved." << endl;
            hashread save_hash;         // create hashread object to access function
            save_hash.readout(authors);     // readout from hashread.cpp outputs every key and corresponding value(s) of authors to .txt file
            cout << "Hash Table Saved." << endl;

            ofstream stats_file;
            stats_file.open("stats_file.txt");      // will store search engine statistics in stats_file.txt
            stats_file << total_words << endl << total_authors << endl << num_articles << endl; //
            for(int v = 0; v < popular_words.size(); v++){  // print out the contents of popular_words in output file
                stats_file << popular_words[v] << "," << popular_freq[v] << endl;
            }
            stats_file.close();

            cout << "Index saved to disk." << endl << endl;
        }

        if(option == 6){
            cout << endl << "  Goodbye!" << endl;
            t = false;      // if t is false, while loop conditions not met
            break;          // break just in case though
        }

        if(option == 7){
            /// function outputs all of our statistic variables:
            cout << endl << "*** Search Engine Stats ***" << endl;
            cout << "Total Number of Words: " << total_words << endl;
            cout << "Total Number of Authors: " << total_authors << endl;
            cout << "Total Number of Documents Parsed: " << num_articles << endl;
            cout << "Average Number of Words Indexed per Article: " << setprecision(2) << fixed << total_words/num_articles << endl;
            cout << "Average Number of Authors per Article: " << setprecision(2) << fixed << total_authors/num_articles << endl;
            cout << "Top 50 Most Popular Words in Database:" << endl;
            cout << "    Word      Freq." << endl << "    ----------------" << endl;
            for(int i = 0; i < popular_words.size(); i++){
                cout << "    " << popular_words[i] << " ";
                for(int j = 0; j < 9-popular_words[i].size(); j++){
                    cout << " ";
                }
                cout << popular_freq[i] << endl;
            }
            cout << endl;
        }
    }
}

void populate_stopwords(set<string>& stop_words){           // populates set with stop words
    ifstream input;
    input.open("C:/Users/Ashwi/OneDrive/Documents/GitHub/search-engine-ashwin-rajesh/stopwords.txt");
    char* temp = new char[50];                              // longest word in english dictionary is 29 chars but we have to accommodate for other "noise" as well
    while(input.getline(temp, 49, '\n')){           // parse through each word in stopwords.txt
        string insert_me = temp;
        stop_words.insert(insert_me);                       // insert stopword into set stop_words
    }
    input.close();
    delete[] temp;
}