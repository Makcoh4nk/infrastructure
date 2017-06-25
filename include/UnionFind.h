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
    UnionFind(int size);
    ~UnionFind();
    void Union(int elem, int parent);
    int Find(int a);

    int operator[](int index) {
        return v[index];
    }
};

#endif  // INCLUDE_UNIONFIND_H_
