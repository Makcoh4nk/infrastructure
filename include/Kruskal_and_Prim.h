#ifndef INCLUDE_KRUSKAL_AND_PRIM_H_
#define INCLUDE_KRUSKAL_AND_PRIM_H_

#include "PriorityQueue.h"
#include "UnionFind.h"
#include <algorithm>
#include <tuple>

using std::tuple;

vector<tuple<int, int, int>> Kruskal(vector<tuple<int, int, int>>, int);
vector<tuple<int, int, int>> Prim(vector<tuple<int,int,int>>, int);

#endif  // INCLUDE_KRUSKAL_AND_PRIM_H_
