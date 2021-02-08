//
// Created by Nacol on 11/20/2020.
//

#ifndef SEARCH_ENGINE_ASHWIN_RAJESH_KEYHASH_H
#define SEARCH_ENGINE_ASHWIN_RAJESH_KEYHASH_H
#define TABLE_SIZE 1001 //prime number modulus
#include <iostream>
#include <type_traits>
#include <ctype.h>


using namespace std;

template<typename K>
struct keyhash{

    unsigned long operator()(const K& key) const{
        char c;
        int a = 0;
        for (int i = 0; i < key.length(); i++){ //saves the string as an int value in the hash table
            c = key[i];
            a += (int)c;
        }

        return static_cast<unsigned long>(a) % TABLE_SIZE; //modulus determines the position of the hash table

    }

};

#endif //SEARCH_ENGINE_ASHWIN_RAJESH_KEYHASH_H