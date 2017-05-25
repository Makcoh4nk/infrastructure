#include "Dijkstra.h"

vector<int> Dijkstra_RB_tree(int start, vector <vector <pair <int, int> > > v) {
    vector <bool> check(v.size(), false);
    vector <int> distance(v.size(), 1000000);
    distance[start] = 0;
    PriorityQueue_on_RBT <pair <int, int> > pq;
    int len = 0;
    pq.Insert(std::make_pair(distance[start], start));

    while (!pq.IsEmpty()) {
        int current_node = pq.GetMin().second;
        pq.DeleteMin();
        if (check[current_node] == false) {
            check[current_node] = true;
            for (unsigned int j = 0; j < v[current_node].size(); ++j) {
                int node = v[current_node][j].second;
                len = v[current_node][j].first;
                if (distance[current_node] + len < distance[node]) {
                    distance[node] = distance[current_node] + len;
                    pq.Insert(std::make_pair(distance[node], node));
                }
            }
        }
    }
    return distance;
}

vector<int> Dijkstra_Six_Heap(int start, vector <vector <pair <int, int> > > v) {
    vector <bool> check(v.size(), false);
    vector <int> distance(v.size(), 1000000);
    distance[start] = 0;
    PriorityQueue_on_HEAP <pair <int, int> > pq;
    int len = 0;

    pq.InsertElem(std::make_pair(distance[start], start));
    while (!pq.IsEmpty()) {
        int current_node = pq.GetMin().second;
        pq.DeleteMin();
        if (check[current_node] == false) {
            check[current_node] = true;
            for (unsigned int j = 0; j < v[current_node].size(); ++j) {
                int node = v[current_node][j].second;
                len = v[current_node][j].first;
                if (distance[current_node] + len < distance[node]) {
                    distance[node] = distance[current_node] + len;
                    pq.InsertElem(std::make_pair(distance[node], node));
                }
            }
        }
    }
    return distance;
}
