#pragma once

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Hash{
    int dim = 0;
    int p = 2;
    vector<pair<int, int>> TAB;
public:
    Hash(const vector<int>&, int P);
    void add(int key);
    void del(int key);
    int findKey(int key) const;
    void print() const;
};
