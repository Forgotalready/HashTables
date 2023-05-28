#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <list>
#include <vector>
#include <algorithm>
#include "Hash.h"
#include<random>
using namespace std;

bool find(const vector<list<int>> &hashTable, int key, int p){
    int h = key % p;
    return any_of(hashTable[h].begin(), hashTable[h].end(), [&](int x){return x == key;});
}

void del(vector<list<int>>& hashTable, int key, int p){
    int h = key % p;
    list<int> t = hashTable[h];
    auto elem = find(t.begin(), t.end(), key);
    if(elem == t.end()) return;
    t.erase(elem);
    hashTable[h] = t;
}

void add(vector<list<int>>& hashTable, int key, int p){
    int h = key % p; // вычисляем хеш
    hashTable[h].emplace_back(key);
}

int main(){
    std::mt19937 mt(228);
    const int n = 20;
    const int p = 7;
    cout << "Метод внешних цепочек\n";
    int h;

    vector<int> a(n, 0);
    // формирование массива случайных чисел.

    for(int i = 0;i < n;i++) a[i] = (rand() % 50);
    // вывод массива случайных чисел
    for(const int& x : a) cout << x << " ";
    cout << "\n";

    // Создание хеш-таблицы (массив списков).

    vector<list<int>> T(p);
    for(int i = 0;i < n;i++){
        add(T, a[i], p);
    }

    // вывод хещ-таблицы
    for(int i = 0;i < p;i++){
        cout << "T[" << i << "]: ";
        for(auto j : T[i]) cout << j << " ";
        cout << "\n";
    }
    //Задать элеменеты x и y. x есть в массиве a, y отсутствует в a.
    // Проверить есть ли элементы в хеш-таблице. Если есть - удалить, если нет - добавить.
    int x = 41;
    int y = 100;
    if(find(T, x, p)){
        cout << "x in T\n";
        del(T, x, p);
    }else{
        cout << "x not in T\n";
        add(T, x, p);
    }

    if(find(T, y, p)){
        cout << "y in T\n";
        del(T, y, p);
    }else{
        cout << "y not in T\n";
        add(T, y, p);
    }

    for(int i = 0;i < p;i++){
        cout << "T[" << i << "]: ";
        for(auto j : T[i]) cout << j << " ";
        cout << "\n";
    }

    cout << "Метод внутренних цепочек\n";
    // создание хеш таблицы
    Hash H(a, p);
    H.print();
    //Задать элеменеты x и y. x есть в массиве a, y отсутствует в a.
    // Проверить есть ли элементы в хеш-таблице. Если есть - удалить, если нет - добавить.
    x = 41;
    y = 100;
    if(H.findKey(x) != -1){
        cout << "x in T\n";
        H.delAll(x);
    }else{
        cout << "x not in T\n";
        H.add(x);
    }

    if(H.findKey(y) !=  -1){
        cout << "y in T\n";
        H.del(y);
    }else{
        cout << "y not in T\n";
        H.add(y);
    }
    H.print();

    system("pause");
    return 0;
}
