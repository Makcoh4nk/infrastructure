#ifndef INCLUDE_ISLANDS_H_
#define INCLUDE_ISLANDS_H_

#include <time.h>
#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int const INF = 1000000;

struct crdnt {
    int str;
    int col;
};

int Find(vector<int> v, int a);
void Union(vector<int>* v1, vector<int>* v2, int a, int b);
void Percolation(vector<vector<int>>* m);
void Sinking(vector<vector<int>>* m);
void Sinking_field(vector<vector<int>> m, vector<vector<int>>* field, crdnt v);

#endif  // INCLUDE_ISLANDS_H_
