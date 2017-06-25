#include "UnionFind.h"

UnionFind::UnionFind() {}

UnionFind::UnionFind(int size) {
    v = vector<int>(size);
    for (int i = 0; i < size; ++i)
        v[i] = i;
}

UnionFind::~UnionFind() {}

void UnionFind::Union(int elem, int parent) {
    int i = Find(elem);
    int j = Find(parent);
    v[j] = i;
}

int UnionFind::Find(int a) {
    if (a > v.size())
        throw std::logic_error("Out of range");
    int res = a;
    while (v[res] != res) {
        res = v[res];
    }
    return res;
}
