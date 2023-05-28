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
    else{ // �������� ��������
        int j;
        // ��������� key � �������.
        for(j = dim - 1;j >= 0;j--){
            if(TAB[j].first == -1){
                TAB[j].first = key;
                break;
            }
        }
        // ����� ���������� �������� ��������.
        int t = h;
        while(TAB[t].second != -1)
            t = TAB[t].second;
        TAB[t].second = j;
    }
}

[[maybe_unused]] int Hash::findKey(int key) const {
    int h = key % p;
    std::pair<int, int> t = TAB[h];
    while(h != -1){
        if(t.first == key) return h;
        h = t.second;
        t = TAB[h];
    }
    return h;
}
[[maybe_unused]] void Hash::del(int key) {
    int h = key % p;
    //��� �� ����� ������� ��������
    while(TAB[h].second != -1) h = TAB[h].second;
    // ������� ������ �������� ��������
    int index = findKey(key);
    // ������ ��� ������� � �������
    swap(TAB[h].first, TAB[index].first);
    //������� ����� �������
    for(int i = 0;i < dim;i++) if(TAB[i].second == h) {TAB[i].second = -1;break;}
    TAB[h].first = -1;
    TAB[h].second = -1;
}

void Hash::print() const {
    for(int i = 0;i < dim;i++){
        cout << TAB[i].first << " ";
    }
    cout << "\n";
    for(int i = 0;i < dim;i++){
        cout << TAB[i].second << " ";
    }
    cout << "\n";
}

