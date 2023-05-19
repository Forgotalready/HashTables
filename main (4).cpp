#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <list>
#include <vector>
#include <algorithm>
#include "Hash.h"

using namespace std;

int main(){
    const int n = 20;
    const int p = 7;
    cout << "Метод внешних цепочек\n";
    int h;

    vector<int> a;
    // формирование массива случайных чисел.

    for(int i = 0;i < n;i++) a.emplace_back(rand() % 50);
    // вывод массива случайных чисел
    for(const int& x : a) cout << x << " ";
    cout << "\n";

    // Создание хеш-таблицы (массив списков).

    vector<list<int>> T(p);
    for(int i = 0;i < n;i++){
        h = a[i] % p; // вычисляем хеш
        T[h].emplace_back(a[i]);
    }

    // вывод хещ-таблицы
    for(int i = 0;i < p;i++){
        cout << "T[" << i << "]: ";
        for(auto j : T[i]) cout << j << " ";
        cout << "\n";
    }
    //Задать элеменеты x и y. x есть в массиве a, y отсутствует в a.
    // Проверить есть ли элементы в хеш-таблице. Если есть - удалить, если нет - добавить.


    cout << "Метод внутренних цепочек\n";
    // создание хеш таблицы

    Hash H(a, p);
    H.print();
    //Задать элеменеты x и y. x есть в массиве a, y отсутствует в a.
    // Проверить есть ли элементы в хеш-таблице. Если есть - удалить, если нет - добавить.
    return 0;
}
