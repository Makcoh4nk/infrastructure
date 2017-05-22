#include "Visual.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    /*vector<vector<int>> graph;

    vector<int> edge1;
    edge1.push_back(1);
    edge1.push_back(1);
    edge1.push_back(0);
    edge1.push_back(0);
    edge1.push_back(0);

    graph.push_back(edge1);

    vector<int> edge2;
    edge2.push_back(1);
    edge2.push_back(0);
    edge2.push_back(1);
    edge2.push_back(0);
    edge2.push_back(0);

    graph.push_back(edge2);

    vector<int> edge3;
    edge3.push_back(1);
    edge3.push_back(0);
    edge3.push_back(0);
    edge3.push_back(1);
    edge3.push_back(0);

    graph.push_back(edge3);

    vector<int> edge4;
    edge4.push_back(1);
    edge4.push_back(0);
    edge4.push_back(0);
    edge4.push_back(0);
    edge4.push_back(1);

    graph.push_back(edge4);

    vector<int> edge5;
    edge5.push_back(0);
    edge5.push_back(0);
    edge5.push_back(0);
    edge5.push_back(1);
    edge5.push_back(1);

    graph.push_back(edge5);

    vector <vector <int> > ostov = Prim(graph);
    vis_graph_ms(graph, ostov);*/

    vector<vector<int>> graph;
    vector< int > edg1;
    edg1.push_back(0);
    edg1.push_back(3);
    edg1.push_back(2);
    edg1.push_back(1);
    edg1.push_back(0);

    graph.push_back(edg1);

    vector< int > edg2;
    edg2.push_back(0);
    edg2.push_back(8);
    edg2.push_back(0);
    edg2.push_back(0);

    graph.push_back(edg2);

    vector< int > edg3;
    edg3.push_back(0);
    edg3.push_back(5);
    edg3.push_back(4);

    graph.push_back(edg3);

    vector< int > edg4;
    edg4.push_back(0);
    edg4.push_back(0);

    graph.push_back(edg4);

    vector< int > edg5;
    edg5.push_back(0);

    graph.push_back(edg5);

    vector <vector <int> > ostov = Kruskal(graph);
    vis_graph_ms(graph, ostov);
}
