//
// Created by Nacol on 11/20/2020.
//

#ifndef SEARCH_ENGINE_ASHWIN_RAJESH_HASHNODE_H
#define SEARCH_ENGINE_ASHWIN_RAJESH_HASHNODE_H

#include <iostream>

template<typename K, typename V>
class hashnode{
private:
    K key;
    V val;
    hashnode *next;

public:
    hashnode(const K &key, const V &val):key(key), val(val), next(NULL){};
    K getkey() const;
    V getval() const;
    void setval(V val);
    hashnode *getnext() const {
        return next;
    };
    void setnext(hashnode *next);

};

template<typename K, typename V>
K hashnode<K, V>::getkey() const { //gets the key of the hash table
    return key;
}

template<typename K, typename V>
V hashnode<K, V>::getval() const { //gets the value of the hash table
    return val;
}

template<typename K, typename V>
void hashnode<K, V>::setval(V val) { //sets the value of the hash table
    hashnode::val = val;
}

template<typename K, typename V>
void hashnode<K, V>::setnext(hashnode *next) { //sets the pointer node of the hash table
    hashnode::next = next;
}

#endif //SEARCH_ENGINE_ASHWIN_RAJESH_HASHNODE_H