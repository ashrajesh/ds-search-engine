//
// Created by Ashwi on 11/22/2020.
//

#ifndef SEARCH_ENGINE_ASHWIN_RAJESH_AVLSUPERROOT_H
#define SEARCH_ENGINE_ASHWIN_RAJESH_AVLSUPERROOT_H

#include "tree_two.h"
#include "word.h"
#include <fstream>

class AVLSuperRoot{
private:
    avl_tree<word> big_tree;

    avlnode<word> *a = nullptr;
    avlnode<word> *b = nullptr;
    avlnode<word> *c = nullptr;
    avlnode<word> *d = nullptr;
    avlnode<word> *e = nullptr;
    avlnode<word> *f = nullptr;
    avlnode<word> *g = nullptr;
    avlnode<word> *h = nullptr;
    avlnode<word> *i = nullptr;
    avlnode<word> *j = nullptr;
    avlnode<word> *k = nullptr;
    avlnode<word> *l = nullptr;
    avlnode<word> *m = nullptr;
    avlnode<word> *n = nullptr;
    avlnode<word> *o = nullptr;
    avlnode<word> *p = nullptr;
    avlnode<word> *q = nullptr;
    avlnode<word> *r = nullptr;
    avlnode<word> *s = nullptr;
    avlnode<word> *t = nullptr;
    avlnode<word> *u = nullptr;
    avlnode<word> *v = nullptr;
    avlnode<word> *w = nullptr;
    avlnode<word> *x = nullptr;
    avlnode<word> *y = nullptr;
    avlnode<word> *z = nullptr;

public:

     void search(word *val){
        switch(val->get_char()) {
            case 97:
                big_tree.search(a, val);
                break;
            case 98:
                big_tree.search(b, val);
                break;
            case 99:
                big_tree.search(c, val);
                break;
            case 100:
                big_tree.search(d, val);
                break;
            case 101:
                big_tree.search(e, val);
                break;
            case 102:
                big_tree.search(f, val);
                break;
            case 103:
                big_tree.search(g, val);
                break;
            case 104:
                big_tree.search(h, val);
                break;
            case 105:
                big_tree.search(i, val);
                break;
            case 106:
                big_tree.search(j, val);
                break;
            case 107:
                big_tree.search(k, val);
                break;
            case 108:
                big_tree.search(a, val);
                break;
            case 109:
                big_tree.search(m, val);
                break;
            case 110:
                big_tree.search(n, val);
                break;
            case 111:
                big_tree.search(o, val);
                break;
            case 112:
                big_tree.search(p, val);
                break;
            case 113:
                big_tree.search(q, val);
                break;
            case 114:
                big_tree.search(r, val);
                break;
            case 115:
                big_tree.search(s, val);
                break;
            case 116:
                big_tree.search(t, val);
                break;
            case 117:
                big_tree.search(u, val);
                break;
            case 118:
                big_tree.search(v, val);
                break;
            case 119:
                big_tree.search(w, val);
                break;
            case 120:
                big_tree.search(x, val);
                break;
            case 121:
                big_tree.search(y, val);
                break;
            case 122:
                big_tree.search(z, val);
                break;
        }
    }

    void insert(word*& val){
        switch(val->get_char()){
            case 97:
                big_tree.insert(a, val);
                break;

            case 98:
                big_tree.insert(b, val);
                break;

            case 99:
                big_tree.insert(c, val);
                break;

            case 100:
                big_tree.insert(d, val);
                break;

            case 101:
                big_tree.insert(e, val);
                break;

            case 102:
                big_tree.insert(f, val);
                break;

            case 103:
                big_tree.insert(g, val);
                break;

            case 104:
                big_tree.insert(h, val);
                break;

            case 105:
                big_tree.insert(i, val);
                break;

            case 106:
                big_tree.insert(j, val);
                break;

            case 107:
                big_tree.insert(k, val);
                break;

            case 108:
                big_tree.insert(l, val);
                break;

            case 109:
                big_tree.insert(m, val);
                break;

            case 110:
                big_tree.insert(n, val);
                break;

            case 111:
                big_tree.insert(o, val);
                break;

            case 112:
                big_tree.insert(p, val);
                break;

            case 113:
                big_tree.insert(q, val);
                break;

            case 114:
                big_tree.insert(r, val);
                break;

            case 115:
                big_tree.insert(s, val);
                break;

            case 116:
                big_tree.insert(t, val);
                break;

            case 117:
                big_tree.insert(u, val);
                break;

            case 118:
                big_tree.insert(v, val);
                break;

            case 119:
                big_tree.insert(w, val);
                break;

            case 120:
                big_tree.insert(x, val);
                break;

            case 121:
                big_tree.insert(y, val);
                break;

            case 122:
                big_tree.insert(z, val);
                break;
        }
    }

    void search_two(word *val, vector<pair<string,int>>& push_me){
        switch(val->get_char()) {
            case 97:
                big_tree.search_two(a, val).push_stuff(push_me);
                break;
            case 98:
                big_tree.search_two(b, val).push_stuff(push_me);
                break;
            case 99:
                big_tree.search_two(c, val).push_stuff(push_me);
                break;
            case 100:
                big_tree.search_two(d, val).push_stuff(push_me);
                break;
            case 101:
                big_tree.search_two(e, val).push_stuff(push_me);
                break;
            case 102:
                big_tree.search_two(f, val).push_stuff(push_me);
                break;
            case 103:
                big_tree.search_two(g, val).push_stuff(push_me);
                break;
            case 104:
                big_tree.search_two(h, val).push_stuff(push_me);
                break;
            case 105:
                big_tree.search_two(i, val).push_stuff(push_me);
                break;
            case 106:
                big_tree.search_two(j, val).push_stuff(push_me);
                break;
            case 107:
                big_tree.search_two(k, val).push_stuff(push_me);
                break;
            case 108:
                big_tree.search_two(a, val).push_stuff(push_me);
                break;
            case 109:
                big_tree.search_two(m, val).push_stuff(push_me);
                break;
            case 110:
                big_tree.search_two(n, val).push_stuff(push_me);
                break;
            case 111:
                big_tree.search_two(o, val).push_stuff(push_me);
                break;
            case 112:
                big_tree.search_two(p, val).push_stuff(push_me);
                break;
            case 113:
                big_tree.search_two(q, val).push_stuff(push_me);
                break;
            case 114:
                big_tree.search_two(r, val).push_stuff(push_me);
                break;
            case 115:
                big_tree.search_two(s, val).push_stuff(push_me);
                break;
            case 116:
                big_tree.search_two(t, val).push_stuff(push_me);
                break;
            case 117:
                big_tree.search_two(u, val).push_stuff(push_me);
                break;
            case 118:
                big_tree.search_two(v, val).push_stuff(push_me);
                break;
            case 119:
                big_tree.search_two(w, val).push_stuff(push_me);
                break;
            case 120:
                big_tree.search_two(x, val).push_stuff(push_me);
                break;
            case 121:
                big_tree.search_two(y, val).push_stuff(push_me);
                break;
            case 122:
                big_tree.search_two(z, val).push_stuff(push_me);
                break;
        }
    }

    void search_three_and(word *val, map<string,int>& push_me, int num){
        switch(val->get_char()) {
            case 97:
                big_tree.search_two(a, val).push_stuff_and(push_me, num);
                break;
            case 98:
                big_tree.search_two(b, val).push_stuff_and(push_me, num);
                break;
            case 99:
                big_tree.search_two(c, val).push_stuff_and(push_me, num);
                break;
            case 100:
                big_tree.search_two(d, val).push_stuff_and(push_me, num);
                break;
            case 101:
                big_tree.search_two(e, val).push_stuff_and(push_me, num);
                break;
            case 102:
                big_tree.search_two(f, val).push_stuff_and(push_me, num);
                break;
            case 103:
                big_tree.search_two(g, val).push_stuff_and(push_me, num);
                break;
            case 104:
                big_tree.search_two(h, val).push_stuff_and(push_me, num);
                break;
            case 105:
                big_tree.search_two(i, val).push_stuff_and(push_me, num);
                break;
            case 106:
                big_tree.search_two(j, val).push_stuff_and(push_me, num);
                break;
            case 107:
                big_tree.search_two(k, val).push_stuff_and(push_me, num);
                break;
            case 108:
                big_tree.search_two(a, val).push_stuff_and(push_me, num);
                break;
            case 109:
                big_tree.search_two(m, val).push_stuff_and(push_me, num);
                break;
            case 110:
                big_tree.search_two(n, val).push_stuff_and(push_me, num);
                break;
            case 111:
                big_tree.search_two(o, val).push_stuff_and(push_me, num);
                break;
            case 112:
                big_tree.search_two(p, val).push_stuff_and(push_me, num);
                break;
            case 113:
                big_tree.search_two(q, val).push_stuff_and(push_me, num);
                break;
            case 114:
                big_tree.search_two(r, val).push_stuff_and(push_me, num);
                break;
            case 115:
                big_tree.search_two(s, val).push_stuff_and(push_me, num);
                break;
            case 116:
                big_tree.search_two(t, val).push_stuff_and(push_me, num);
                break;
            case 117:
                big_tree.search_two(u, val).push_stuff_and(push_me, num);
                break;
            case 118:
                big_tree.search_two(v, val).push_stuff_and(push_me, num);
                break;
            case 119:
                big_tree.search_two(w, val).push_stuff_and(push_me, num);
                break;
            case 120:
                big_tree.search_two(x, val).push_stuff_and(push_me, num);
                break;
            case 121:
                big_tree.search_two(y, val).push_stuff_and(push_me, num);
                break;
            case 122:
                big_tree.search_two(z, val).push_stuff_and(push_me, num);
                break;
        }
    }

    void search_three_or(word *val, map<string,int>& push_me){
        switch(val->get_char()) {
            case 97:
                big_tree.search_two(a, val).push_stuff_or(push_me);
                break;
            case 98:
                big_tree.search_two(b, val).push_stuff_or(push_me);
                break;
            case 99:
                big_tree.search_two(c, val).push_stuff_or(push_me);
                break;
            case 100:
                big_tree.search_two(d, val).push_stuff_or(push_me);
                break;
            case 101:
                big_tree.search_two(e, val).push_stuff_or(push_me);
                break;
            case 102:
                big_tree.search_two(f, val).push_stuff_or(push_me);
                break;
            case 103:
                big_tree.search_two(g, val).push_stuff_or(push_me);
                break;
            case 104:
                big_tree.search_two(h, val).push_stuff_or(push_me);
                break;
            case 105:
                big_tree.search_two(i, val).push_stuff_or(push_me);
                break;
            case 106:
                big_tree.search_two(j, val).push_stuff_or(push_me);
                break;
            case 107:
                big_tree.search_two(k, val).push_stuff_or(push_me);
                break;
            case 108:
                big_tree.search_two(a, val).push_stuff_or(push_me);
                break;
            case 109:
                big_tree.search_two(m, val).push_stuff_or(push_me);
                break;
            case 110:
                big_tree.search_two(n, val).push_stuff_or(push_me);
                break;
            case 111:
                big_tree.search_two(o, val).push_stuff_or(push_me);
                break;
            case 112:
                big_tree.search_two(p, val).push_stuff_or(push_me);
                break;
            case 113:
                big_tree.search_two(q, val).push_stuff_or(push_me);
                break;
            case 114:
                big_tree.search_two(r, val).push_stuff_or(push_me);
                break;
            case 115:
                big_tree.search_two(s, val).push_stuff_or(push_me);
                break;
            case 116:
                big_tree.search_two(t, val).push_stuff_or(push_me);
                break;
            case 117:
                big_tree.search_two(u, val).push_stuff_or(push_me);
                break;
            case 118:
                big_tree.search_two(v, val).push_stuff_or(push_me);
                break;
            case 119:
                big_tree.search_two(w, val).push_stuff_or(push_me);
                break;
            case 120:
                big_tree.search_two(x, val).push_stuff_or(push_me);
                break;
            case 121:
                big_tree.search_two(y, val).push_stuff_or(push_me);
                break;
            case 122:
                big_tree.search_two(z, val).push_stuff_or(push_me);
                break;
        }
    }

    void search_three_not(word *val, map<string,int>& push_me){
        switch(val->get_char()) {
            case 97:
                big_tree.search_two(a, val).push_stuff_not(push_me);
                break;
            case 98:
                big_tree.search_two(b, val).push_stuff_not(push_me);
                break;
            case 99:
                big_tree.search_two(c, val).push_stuff_not(push_me);
                break;
            case 100:
                big_tree.search_two(d, val).push_stuff_not(push_me);
                break;
            case 101:
                big_tree.search_two(e, val).push_stuff_not(push_me);
                break;
            case 102:
                big_tree.search_two(f, val).push_stuff_not(push_me);
                break;
            case 103:
                big_tree.search_two(g, val).push_stuff_not(push_me);
                break;
            case 104:
                big_tree.search_two(h, val).push_stuff_not(push_me);
                break;
            case 105:
                big_tree.search_two(i, val).push_stuff_not(push_me);
                break;
            case 106:
                big_tree.search_two(j, val).push_stuff_not(push_me);
                break;
            case 107:
                big_tree.search_two(k, val).push_stuff_not(push_me);
                break;
            case 108:
                big_tree.search_two(a, val).push_stuff_not(push_me);
                break;
            case 109:
                big_tree.search_two(m, val).push_stuff_not(push_me);
                break;
            case 110:
                big_tree.search_two(n, val).push_stuff_not(push_me);
                break;
            case 111:
                big_tree.search_two(o, val).push_stuff_not(push_me);
                break;
            case 112:
                big_tree.search_two(p, val).push_stuff_not(push_me);
                break;
            case 113:
                big_tree.search_two(q, val).push_stuff_not(push_me);
                break;
            case 114:
                big_tree.search_two(r, val).push_stuff_not(push_me);
                break;
            case 115:
                big_tree.search_two(s, val).push_stuff_not(push_me);
                break;
            case 116:
                big_tree.search_two(t, val).push_stuff_not(push_me);
                break;
            case 117:
                big_tree.search_two(u, val).push_stuff_not(push_me);
                break;
            case 118:
                big_tree.search_two(v, val).push_stuff_not(push_me);
                break;
            case 119:
                big_tree.search_two(w, val).push_stuff_not(push_me);
                break;
            case 120:
                big_tree.search_two(x, val).push_stuff_not(push_me);
                break;
            case 121:
                big_tree.search_two(y, val).push_stuff_not(push_me);
                break;
            case 122:
                big_tree.search_two(z, val).push_stuff_not(push_me);
                break;
        }
    }

    void pre_order(word val){
         ofstream output_file;
         output_file.open("persistent_index.txt");

         big_tree.level_order(a, output_file);
         big_tree.level_order(b, output_file);
         big_tree.level_order(c, output_file);
         big_tree.level_order(d, output_file);
         big_tree.level_order(e, output_file);
         big_tree.level_order(f, output_file);
         big_tree.level_order(g, output_file);
         big_tree.level_order(h, output_file);
         big_tree.level_order(i, output_file);
         big_tree.level_order(j, output_file);
         big_tree.level_order(k, output_file);
         big_tree.level_order(l, output_file);
         big_tree.level_order(m, output_file);
         big_tree.level_order(n, output_file);
         big_tree.level_order(o, output_file);
         big_tree.level_order(p, output_file);
         big_tree.level_order(q, output_file);
         big_tree.level_order(r, output_file);
         big_tree.level_order(s, output_file);
         big_tree.level_order(t, output_file);
         big_tree.level_order(u, output_file);
         big_tree.level_order(v, output_file);
         big_tree.level_order(w, output_file);
         big_tree.level_order(x, output_file);
         big_tree.level_order(y, output_file);
         big_tree.level_order(z, output_file);

         output_file.close();
    }

    void load_order(){
        ofstream output_file;
        output_file.open("persistent_index.txt");

        big_tree.level_order(a, output_file);
        big_tree.level_order(b, output_file);
        big_tree.level_order(c, output_file);
        big_tree.level_order(d, output_file);
        big_tree.level_order(e, output_file);
        big_tree.level_order(f, output_file);
        big_tree.level_order(g, output_file);
        big_tree.level_order(h, output_file);
        big_tree.level_order(i, output_file);
        big_tree.level_order(j, output_file);
        big_tree.level_order(k, output_file);
        big_tree.level_order(l, output_file);
        big_tree.level_order(m, output_file);
        big_tree.level_order(n, output_file);
        big_tree.level_order(o, output_file);
        big_tree.level_order(p, output_file);
        big_tree.level_order(q, output_file);
        big_tree.level_order(r, output_file);
        big_tree.level_order(s, output_file);
        big_tree.level_order(t, output_file);
        big_tree.level_order(u, output_file);
        big_tree.level_order(v, output_file);
        big_tree.level_order(w, output_file);
        big_tree.level_order(x, output_file);
        big_tree.level_order(y, output_file);
        big_tree.level_order(z, output_file);

        output_file.close();
    }
};


#endif //SEARCH_ENGINE_ASHWIN_RAJESH_AVLSUPERROOT_H
