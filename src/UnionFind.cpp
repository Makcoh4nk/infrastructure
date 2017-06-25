#include "UnionFind.h"

UnionFind::UnionFind() {}

UnionFind::~UnionFind() {}

void UnionFind::Union(int elem, int parent) {
    int i = Find(elem);
    int j = Find(parent);
    v[j] = i;
}

int UnionFind::Find(int a) {
    int size = v.size();
    if (a > size)
        throw 1;
    int res = a;
    while (v[res] != res) {
        res = v[res];
    }
    return res;
}
