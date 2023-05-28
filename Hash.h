#pragma once

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Hash{
    int dim = 0; // размерность массива
    int p = 2;
    vector<pair<int, int>> TAB;
public:
    Hash(const vector<int>&, int P);
    void add(int key);

    [[maybe_unused]] void del(int key);

    [[maybe_unused]] int findKey(int key) const;
    void print() const;
    void delAll(int key){
        while(findKey(key) != -1){
            del(key);
        }
    }
};
