#include "UnionFind.h"

UnionFind::UnionFind() {}

UnionFind::UnionFind(int size) {
    v = vector<int>(size);
}

UnionFind::~UnionFind() {}

void UnionFind::Union(int elem, int parent) {
    int i = Find(elem);
    int j = Find(parent);
    v[i] = j;
}

int UnionFind::Find(int elem) {
    int res = elem;
    while (v[res] != res) {
        res = v[res];
    }
    return res;
}
