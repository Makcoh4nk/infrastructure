#include "Kruskal_and_Prim.h"

#define INF 1000000

using std::make_pair;
using std::get;

vector<tuple<int, int, int>>
    Kruskal(vector<tuple<int, int, int>> graph, int count_v) {
    vector<tuple<int, int, int>> spanning_tree;
    PriorityQueue<tuple<int, int, int>> pq;
    tuple<int, int, int> min_edge;
    UnionFind uf(count_v);
    int size = graph.size();

    for (int i = 0; i < size; ++i)
        pq.InsertElem(graph[i]);

    int i = 0;
    while ((i != count_v - 1) && !pq.IsEmpty()) {
        min_edge = pq.GetMin();
        pq.DeleteMin();
        if (uf.Find(get<1>(min_edge)) != uf.Find(get<2>(min_edge))) {
            uf.Union(get<1>(min_edge), get<2>(min_edge));
            spanning_tree.push_back(min_edge);
            i++;
        }
    }
    if (i < count_v - 1)
        throw std::logic_error("Graph is disconnected!");
    return spanning_tree;
}

vector<tuple<int, int, int>> 
    Prim(vector<tuple<int, int, int>> graph, int count_v) {
    vector<tuple<int, int, int>> spanning_tree;
    PriorityQueue<tuple<int, int, int>> pq;
    vector<bool> used(count_v, false);
    tuple<int, int, int> min_edge;
    int size = graph.size();
    int v = 0;
    int i = 0;

    for (i = 0; i < count_v - 1; ++i) {
        used[v] = true;
        for (int j = 0; j < size; ++j)
            if ((get<1>(graph[j]) == v && !used[get<2>(graph[j])])
                || (get<2>(graph[j]) == v && !used[get<1>(graph[j])]))
                    pq.InsertElem(graph[j]);

        if (!pq.IsEmpty()) {
            do {
                min_edge = pq.GetMin();
                pq.DeleteMin();
            } while (used[get<1>(min_edge)] && used[get<2>(min_edge)]);

            spanning_tree.push_back(min_edge);
            if (used[get<1>(min_edge)])
                v = get<2>(min_edge);
            else
                v = get<1>(min_edge);
        } else {
            throw std::logic_error("Graph is disconnected!");
        }
    }
    return spanning_tree;
}
