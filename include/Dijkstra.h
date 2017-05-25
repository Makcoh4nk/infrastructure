#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_

#include "PriorityQueue.h"
#include <vector>

using std::vector;

vector<int> Dijkstra_Six_Heap(int start, vector <vector <pair <int, int> > > v);
vector<int> Dijkstra_RB_tree(int start, vector <vector <pair <int, int> > > v);

#endif  // INCLUDE_DIJKSTRA_H_
