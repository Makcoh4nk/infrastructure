#include <set>
#include "Dijkstra.h"

std::vector<int> Dijkstra(std::vector <
    std::vector <std::pair <int, int > > > v, int start) {
    if (v.size() == 0) {
        throw std::logic_error("Graph size = 0");
    }
    std::vector<int> dist(v.size(), INF);
    dist[start] = 0;
    std::set< std::pair<int, int> > unused;
    unused.insert(std::make_pair(0, start));
    while (!unused.empty()) {
        int i = unused.begin()->second;
        unused.erase(unused.begin());
        for (auto edge : v[i]) {
            int j = edge.first;
            int wt = edge.second;
            if (dist[i] + wt < dist[j]) {
                unused.erase(std::make_pair(dist[j], j));
                dist[j] = dist[i] + wt;
                unused.insert(std::make_pair(dist[j], j));
            }
        }
    }
    return dist;
}
