#ifndef INCLUDE_VISUAL_H_
#define INCLUDE_VISUAL_H_

#define INF 100000

#include "Kruskal_and_Prim.h"
#include <vector>

using std::vector;

vector<vector<int>> Reading_the_matrix(char*);
vector<tuple<int, int, int>> Init_graph_from_adjacency_matrix(vector<vector<int>>);
vector<tuple<int, int, int>> Init_graph_from_incidence_matrix(vector<vector<int>>);
void Graphviz(vector<tuple<int, int, int>>, vector<tuple<int, int, int>>);

#endif // INCLUDE_VISUAL_H_
