#include "Prim.h"

tuple<int, int, int> EDGE(vector<int> s) {
    int v1;
    int v2;
    for (unsigned int i = 1, j = 0; i < s.size() && j < 3; ++i) {
        if (s[i] == 1) {
            if (j == 0) {
                v1 = i;
                ++j;
            } else {
                v2 = i;
                ++j;
            }
        }
    }
    tuple<int, int, int> t = std::make_tuple(s[0], v1, v2);
    return t;
}

vector<vector<int>> Prim(vector<vector<int>> graph) {
    if (graph.size() != 0) {
        vector<bool> visited(graph.size(), false);
        vector<vector<int>> ostov;
        tuple<int, int, int> edge = EDGE(graph[0]);
        Five_Heap<tuple<int, int, int>> h;
        h.InsertElem(edge);
        visited[0] = true;
        unsigned int n = 0;
        while (!h.IsEmpty() && n < graph[0].size() - 2) {
            tuple<int, int, int> min_edge = h.GetMin();
            h.DeleteMin();
            vector<int> new_edge(graph[0].size());
            new_edge[0] = std::get<0>(min_edge);
            for (unsigned int i = 1; i < new_edge.size(); ++i) {
                unsigned int e = std::get<1>(min_edge);
                unsigned int c = std::get<2>(min_edge);
                if (i == e || i == c) {
                    new_edge[i] = 1;
                } else {
                    new_edge[i] = 0;
                }
            }
            ostov.push_back(new_edge);
            n++;
            for (unsigned int i = 0; i < graph.size(); ++i) {
                if ((graph[i][std::get<1>(min_edge)] == 1 ||
                    graph[i][std::get<2>(min_edge)] == 1) && visited[i] == false) {
                    h.InsertElem(EDGE(graph[i]));
                    visited[i] = true;
                }
            }
        }
        return ostov;
    } else {
        throw 1;
    }
}
