//
// Created by Nathan (mostly) & Ashwin
//

#ifndef SEARCH_ENGINE_ASHWIN_RAJESH_TREE_TWO_H
#define SEARCH_ENGINE_ASHWIN_RAJESH_TREE_TWO_H

#include "word.h"
#include <typeinfo>
#include <iostream>
#include <queue>

template<class T>
struct avlnode {
    T* d; //data
    //word y;
    avlnode *l; //left node
    avlnode *r; //right node
    int height; //height int of the tree
    int count = 1; //insert will have 1 already
};

template<class T>
class avl_tree {
public:
    avlnode<T>* r;
    int height(avlnode<T>*);
    int difference(avlnode<T>*);
    avlnode<T>* rr_rotat(avlnode<T>*);
    avlnode<T>* ll_rotat(avlnode<T>*);
    avlnode<T>* lr_rotat(avlnode<T>*);
    avlnode<T>* rl_rotat(avlnode<T>*);
    avlnode<T>* balance(avlnode<T>*);
    avlnode<T>* insert(avlnode<T>*&, T*&);
    void show(avlnode<T>*, T&);
    void inorder(avlnode<T>*, ofstream& output_file);
    void level_order(avlnode<T>* t, ofstream &output_file);
    void preorder(avlnode<T>*);
    void postorder(avlnode<T>*);
    avlnode<T>* search(avlnode<T> *& root, T*& val);
    T search_two(avlnode<T>*& root, T*& val);
    avl_tree() {
        r = NULL;
    }
};

template<class T>
int avl_tree<T>::height(avlnode<T>* t) { //returns the height of the AVL tree
    int h = 0;
    if (t != NULL) {
        int l_height = height(t->l);
        int r_height = height(t->r);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

template<class T>
int avl_tree<T>::difference(avlnode<T>* t) { //returns the difference between the heihgt of left child and the height of the right child
    int l_height = height(t->l);
    int r_height = height(t->r);
    int b_factor = l_height - r_height;
    return b_factor;
}

template<class T>
avlnode<T>* avl_tree<T>::rr_rotat(avlnode<T>* parent) { //right right rotation function
    avlnode<T> *t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
//    cout<<"Right-Right Rotation";
    return t;
}

template<class T>
avlnode<T>* avl_tree<T>::ll_rotat(avlnode<T>* parent) { //left left rotation function
    avlnode<T> *t;
    t = parent->l;
    parent->l = t->r;
    t->r = parent;
//    cout<<"Left-Left Rotation";
    return t;
}

template<class T>
avlnode<T>* avl_tree<T>::lr_rotat(avlnode<T>* parent) { //left right rotation function
    avlnode<T>* t;
    t = parent->l;
    parent->l = rr_rotat(t);
//    cout<<"Left-Right Rotation";
    return ll_rotat(parent);
}

template<class T>
avlnode<T>* avl_tree<T>::rl_rotat(avlnode<T>* parent) { //right left rotation function
    avlnode<T> *t;
    t = parent->r;
    parent->r = ll_rotat(t);
//    cout<<"Right-Left Rotation";
    return rr_rotat(parent);
}

template<class T>
avlnode<T>* avl_tree<T>::balance(avlnode<T>* t) { //balances the branches on the tree using rr, ll, rl, and rr functions
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->l) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    } else if (bal_factor < -1) {
        if (difference(t->r) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}

template<class T>
avlnode<T>* avl_tree<T>::insert(avlnode<T>* &r, T*& v) { //inserts new node to the tree
    if (r == NULL) {
        r = new avlnode<T>;
        r->d = v;
        r->l = NULL;
        r->r = NULL;
        return r;
    } else if (*v < *(r->d)) {
        r->l = insert(r->l, v);
        r = balance(r);
    } else {
        r->r = insert(r->r, v);
        r = balance(r);
    } return r;
}

template<class T>
void avl_tree<T>::show(avlnode<T>* p, T& l) { //displays the root node of the tree
    int i;
    if (p != NULL) {
        show(p->r, l+ 1);
        cout<<" ";
        if (p == r)
            cout << "Root -> ";
        for (i = 0; i < l&& p != r; i++)
            cout << " ";
        cout << p->d;
        show(p->l, l + 1);
    }
}

template<class T>
void avl_tree<T>::inorder(avlnode<T>* t, ofstream &output_file) { //traverses the tree inorder
    if (t == NULL)
        return;
    inorder(t->l, output_file);
    cout << *(t->d) << " ";
    output_file << *(t->d);
    inorder(t->r, output_file);
}

template<class T>
void avl_tree<T>::level_order(avlnode<T>* t, ofstream &output_file){ //traverses the tree by level order [goes through every level in the tree] (optimal for insertion from persistent index)
    if(t == NULL){

    }
    queue<avlnode<T>*> node_queue;
    node_queue.push(t);
    //cout << *(t->d);
    output_file << *(t->d); /// outputs to text file via overloaded << operator
    node_queue.pop();
    node_queue.push(t->l);
    node_queue.push(t->r);
    while(!node_queue.empty()) { ///
        avlnode<T> *curr_node = node_queue.front();
        //cout << *(curr_node->d);
        output_file << *(curr_node->d); ///
        node_queue.pop();
        if(curr_node->l != NULL) { ///
            node_queue.push(curr_node->l);
        } ///
        if(curr_node->r != NULL) { ///
            node_queue.push(curr_node->r);
        } ///
    } ///
    // while loop should continue until queue empty
    // only push nodes onto queu if left not null (same with right)
}


template<class T>
void avl_tree<T>::preorder(avlnode<T>* t) { //traverses the tree by preorder
    if (t == NULL)
        return;
    cout << *t->d << " ";
    preorder(t->l);
    preorder(t->r);
}

template<class T>
void avl_tree<T>::postorder(avlnode<T> *t) { //traverses the tree by postorder
    if (t == NULL)
        return;
    postorder(t ->l);
    postorder(t ->r);
    cout << t->d << " ";
}

template<class T>
avlnode<T>* avl_tree<T>::search(avlnode<T> *& root, T*& val){ //searches for a particular node in the tree
    if (root == NULL){
        return NULL;
    }
    if (*root->d == *val){
        return root;
    }
    if (*root->d > *val){
        return search(root->l, val);
    }
    if (*root->d < *val){
        return search(root->r, val);
    }
    else{
        cout << "Sorry, we could not find any documents that matched your search criteria :(" << endl;
        exit(-1); //query was not found
    }


}


template<class T>
T avl_tree<T>::search_two(avlnode<T> *& root, T*& val){ //alternative search function that utilizes pointers
    if (root == NULL){
        ///cout << "Uh oh, it appears that we don't have this search term in our database!" << endl;
        return word("NULL");
    }
    if (*root->d == *val){
        return *root->d;
    }
    if (*root->d > *val){
        return search_two(root->l, val);
    }
    if (*root->d < *val){
        return search_two(root->r, val);
    }
    else{
        cout << "Sorry, we could not find any documents that matched your search criteria :(" << endl << endl;
        exit(-1); //query was not found
    }
}


#endif //SEARCH_ENGINE_ASHWIN_RAJESH_TREE_TWO_H
