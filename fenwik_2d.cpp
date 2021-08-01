//
// 2D Fenwick Tree
//
// Description:
//   A data structure that allows
//     add(k,a): x[k] += a
//     sum(k):   sum { x[i] : i <= k }
//   where k denotes a point in [0,n)x[0,m).
//
// Algorithm:
//   Fenwick tree of Fenwick tree.
//
// Complexity:
//   O((log n)^2) time, O(n^2) space.
//
// Verified:
//   SPOJ1029

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

template <class T>
struct fenwick_tree_2d
{
    vector<vector<T>> x;
    fenwick_tree_2d(int n, int m) : x(n, vector<T>(m)) {}
    void add(int k1, int k2, int a)
    { // x[k] += a
        for (; k1 < x.size(); k1 |= k1 + 1)
            for (int k = k2; k < x[k1].size(); k |= k + 1)
                x[k1][k] += a;
    }
    T sum(int k1, int k2)
    { // return x[0] + ... + x[k]
        T s = 0;
        for (; k1 >= 0; k1 = (k1 & (k1 + 1)) - 1)
            for (int k = k2; k >= 0; k = (k & (k + 1)) - 1)
                s += x[k1][k];
        return s;
    }
};

int main(){

    fenwick_tree_2d<int> ft(6,6);

    for (int i = 0; i < 6;i++){
        for (int j = 0; j < 6;j++)
            ft.add(i, j, 1);
    
    }
    ft.add(1, 1, 1);
    cout << ft.sum(3, 3);

}