//
// Created by Ashwi on 11/14/2020.
//

#ifndef SEARCH_ENGINE_ASHWIN_RAJESH_HASH_TABLE_H
#define SEARCH_ENGINE_ASHWIN_RAJESH_HASH_TABLE_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "hashnode.h"
#include "keyhash.h"

using namespace std;

template<class K, class V, typename F = keyhash<K>>

class hash_table {
private:
    hashnode<K, V> **table;
    F hashfunc;
public:

    vector<K> keys; //vector of keys
    hash_table();
    ~hash_table();
    bool get(const K &key, V &val);
    void insert(const K &key, const V &val);
    void remove(const K &key);
};

template<class K, class V, typename F>
hash_table<K,V,F>::hash_table() //constructor
{
    table = new hashnode<K, V> *[TABLE_SIZE](); //table is initialized to table size
}

template<class K, class V, typename F>
hash_table<K, V, F>::~hash_table(){ //destructor
    for (int i = 0; i < TABLE_SIZE; i++){
        hashnode<K, V> *entry = table[i];
        while (entry != NULL){
            hashnode<K, V> *prev = entry;
            entry = entry->getnext();
            delete prev;
        }
        table[i] = NULL;
    }
    delete [] table;
}

template<class K, class V, typename F>
bool hash_table<K,V, F>::get(const K &key, V &val) //searches for key in hash table
{
    unsigned long hashval = hashfunc(key);
    hashnode<K, V> *entry = table[hashval];
    while (entry != NULL) {
        if (entry->getkey() == key){
            val = entry->getval();
            return true;
        }
        entry = entry->getnext();
    }
    return false;
}

template<class K, class V, typename F>
void hash_table<K, V, F>::insert(const K &key, const V &val) { //inserts values into the hash table
    unsigned long hashval = hashfunc(key);
    hashnode<K, V> *prev = NULL;
    hashnode<K, V> *entry = table[hashval];

    while (entry != NULL && entry->getkey() != key) {
        prev = entry;
        entry = entry->getnext();
    }

    if (entry == NULL) {
        entry = new hashnode<K, V>(key, val);
        keys.push_back(key); //push into vector of keys
        if (prev == NULL){
            table[hashval] = entry;
        }
        else {
            prev->setnext(entry);
        }
    }
    else {
        entry->setval(val);
    }
}

template<class K, class V, typename F>
void hash_table<K, V, F>::remove(const K &key){ //removes value from the hash table
    unsigned long hashval = hashfunc(key);
    hashnode<K, V> *prev = NULL;
    hashnode<K, V> *entry = table[hashval];

    while (entry != NULL && entry->getKey() != key){
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == NULL) {
        return;
    }
    else {
        if (prev == NULL){
            table[hashval] = entry->getNext();
        }
        else {
            prev->setNext(entry->getNext());
        }
        delete entry;
    }
}


#endif //SEARCH_ENGINE_ASHWIN_RAJESH_HASH_TABLE_H