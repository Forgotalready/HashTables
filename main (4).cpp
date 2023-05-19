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
    cout << "����� ������� �������\n";
    int h;

    vector<int> a;
    // ������������ ������� ��������� �����.

    for(int i = 0;i < n;i++) a.emplace_back(rand() % 50);
    // ����� ������� ��������� �����
    for(const int& x : a) cout << x << " ";
    cout << "\n";

    // �������� ���-������� (������ �������).

    vector<list<int>> T(p);
    for(int i = 0;i < n;i++){
        h = a[i] % p; // ��������� ���
        T[h].emplace_back(a[i]);
    }

    // ����� ���-�������
    for(int i = 0;i < p;i++){
        cout << "T[" << i << "]: ";
        for(auto j : T[i]) cout << j << " ";
        cout << "\n";
    }
    //������ ��������� x � y. x ���� � ������� a, y ����������� � a.
    // ��������� ���� �� �������� � ���-�������. ���� ���� - �������, ���� ��� - ��������.


    cout << "����� ���������� �������\n";
    // �������� ��� �������

    Hash H(a, p);
    H.print();
    //������ ��������� x � y. x ���� � ������� a, y ����������� � a.
    // ��������� ���� �� �������� � ���-�������. ���� ���� - �������, ���� ��� - ��������.
    return 0;
}
