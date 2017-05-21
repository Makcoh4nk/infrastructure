#include "Dijkstra.h"

#include <vector>

vector<int> Dijkstra_RB_tree(int start, vector <vector <pair <int, int> > > v) {
    int n = v.size();
    bool* m = new bool[n];
    for (int i = 0; i < n; ++i)
        m[i] = false;
    vector <int> distance(n, 1000000);
    distance[start] = 0;
    RB_PriorityQueue < pair <int, int> > q;
    int len = 0;
    q.Insert(std::make_pair(distance[start], start));

    while (!q.IsEmpty()) {
        int current_node = q.GetMin().second;
        q.DeleteMin();
        if (m[current_node] == false) {
            m[current_node] = true;
            for (unsigned int j = 0; j < v[current_node].size(); ++j) {
                int node = v[current_node][j].second;
                len = v[current_node][j].first;
                if (distance[current_node] + len < distance[node]) {
                    distance[node] = distance[current_node] + len;
                    q.Insert(std::make_pair(distance[node], node));
                }
            }
        }
    }
    return distance;
}

vector<int> Dijkstra_Six_Heap(int start, vector <vector <pair <int, int> > > v) {
    int n = v.size();
    bool* m = new bool[n];

    for (int i = 0; i < n; ++i)
        m[i] = false;

    vector <int> distance(n, 1000000);
    distance[start] = 0;
    H_PriorityQueue < pair < int, int> > q;
    int len;

    q.InsertElem(std::make_pair(distance[start], start));
    while (!q.IsEmpty()) {
        int current_node = q.GetMin().second;
        q.DeleteMin();
        if (m[current_node] == false) {
            m[current_node] = true;
            for (unsigned int j = 0; j < v[current_node].size(); ++j) {
                int node = v[current_node][j].second;
                len = v[current_node][j].first;
                if (distance[current_node] + len < distance[node]) {
                    distance[node] = distance[current_node] + len;
                    q.InsertElem(std::make_pair(distance[node], node));
                }
            }
        }
    }
    return distance;
}
