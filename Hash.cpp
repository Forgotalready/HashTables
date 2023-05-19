#include "Hash.h"

Hash::Hash(const vector<int>& a, int P){
    const int n = a.size();
    dim = (1.2)*n;
    p = P;
    pair<int, int> pa = {-1, -1};
    TAB.resize(dim, pa);
    for(const int& x : a) add(x);
}

void Hash::add(int key){
    int h = key % p;
    if(TAB[h].first == -1) TAB[h].first = key;
    else{ // Возникла коллизия
        int j;
        // размещаем key в таблице.
        for(j = dim - 1;j >= 0;j--){
            if(TAB[j].first == -1){
                TAB[j].first = key;
                break;
            }
        }
        // Поиск последнего элемента коллизии.
        int t = h;
        while(TAB[t].second != -1)
            t = TAB[t].second;
        TAB[t].second = j;
    }
}
