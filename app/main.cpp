#include "Visual.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
    vector<tuple<int, int, int>> graph;
    vector<tuple<int, int, int>> spanning_tree;
    vector<vector<int>> Adjacency_Matrix;
    vector<vector<int>> Incidence_Matrix;
    char path_to_file_Kruskal[150] =
        "C:\\Users\\HP\\Desktop\\tmp\\infrastructure\\Kruskal.txt";
    char path_to_file_Prim[150] =
        "C:\\Users\\HP\\Desktop\\tmp\\infrastructure\\Prim.txt";
    int count_v = 0;
    int select = 1;   // Set 1 to Prim's algorithm or 2 to Kruskal's algorithm

    switch (select) {
    case 1:
        cout << "KRUSKAL`S ALGORITHM\n";
        cout << "Path to file: " << path_to_file_Kruskal << endl;
        Adjacency_Matrix = Reading_the_matrix(path_to_file_Kruskal);
        count_v = Adjacency_Matrix[0].size();
        graph = Init_graph_Adjacency_matrix(Adjacency_Matrix);
        spanning_tree = Kruskal(graph, count_v);
        break;

    case 2:
        cout << "PRIM`S ALGORITHM\n";
        cout << "Path to file: " << path_to_file_Prim << endl;
        Incidence_Matrix = Reading_the_matrix(path_to_file_Prim);
        count_v = Incidence_Matrix[0].size();
        graph = Init_graph_Incidence_matrix(Incidence_Matrix);
        spanning_tree = Prim(graph, count_v);
        break;
    }
    Graphviz(graph, spanning_tree);
    cout << "\n************\n* SUCCESS! *\n************\n\n" <<
        "Open file: C:/Users/HP/Desktop/tmp/infrastructure/Graphviz.txt\n\n";
}
