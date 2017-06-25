#ifndef INCLUDE_UNIONFIND_H_
#define INCLUDE_UNIONFIND_H_

#include <vector>
#include <tuple>
#include <algorithm>

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

    int operator[](int index) {
        return v[index];
    }
};

#endif  // INCLUDE_UNIONFIND_H_
