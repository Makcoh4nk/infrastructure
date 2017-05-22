#ifndef INCLUDE_UNIONFIND_H_
#define INCLUDE_UNIONFIND_H_

#include <vector>
#include <tuple>
#include <algorithm>

const int MAX = 100000;

using std::vector;
using std::tuple;

class UnionFind {

    vector<int> v;

public:

    UnionFind();
    UnionFind(int);
    ~UnionFind();
    void Union(int, int);
    int Find(int);

};

#endif  // INCLUDE_UNIONFIND_H_
