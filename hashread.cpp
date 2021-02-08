//
// Created by Ashwin
//

#include "hashread.h"
#include <vector>
#include <fstream>
#include "hash_table.h"
#include <sstream>

void hashread::readin(hash_table<string, vector<string>> &testhash){
    ifstream auth_index;
    auth_index.open("authors.txt");

    char* temp = new char[1000000];
    int county = 0;
    while(auth_index.getline(temp,999999,'\n')){
        //cout << county << endl;
        //cout << temp << endl;
        stringstream streamer(temp);
        vector<string> elements;
        string auth_name;
        int index_stop = 0;
        while(streamer.getline(temp,9999,',')){
            string push_me = temp;
            if(index_stop == 0){
                auth_name = temp;
            }
            else {
                elements.push_back(push_me);
            }
            index_stop++;
        }
        //cout << auth_name << " " << elements[0] << endl;
        testhash.insert(auth_name, elements);
    }
}

void hashread::readout(hash_table<string, vector<string>> &testhash) { //will also modify this more
    //persistent index
    ofstream ofile;
    ofile.open("authors.txt");
    vector<string> var;

    for (int i = 0; i < testhash.keys.size(); i++){
        ofile << testhash.keys.at(i); //prints out the key
        ofile << ",";
        testhash.get(testhash.keys.at(i), var);
        for(int j = 0; j < var.size(); j++) {
            if(j == var.size()-1){ofile<<var[j]<<endl;break;}
            ofile << var[j] << ",";
        }
        //ofile << endl;
    }

    ofile.close();
}