#ifndef INCLUDE_PRIM_H_
#define INCLUDE_PRIM_H_

#include "5-Heap.h"
#include <algorithm>
#include <tuple>

using std::tuple;

vector<vector<int>> Prim(vector<vector<int>> graph);
std::tuple<int, int, int> EDGE(vector<int> s);

#endif  // INCLUDE_PRIM_H_
