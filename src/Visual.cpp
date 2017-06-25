#include "Visual.h"

using std::get;

vector<vector<int>> Reading_the_matrix(char* path) {
    FILE* f = fopen(path, "r");
    if (f == 0)
        throw std::logic_error("Error! Can`t open the file!");
    vector<vector<int>> graph;
    int ch = 0;
    vector<int>* v = new vector<int>;
    while ((ch = fgetc(f)) != EOF) {
        if (ch != ' ') {
            if (ch == '\n') {
                graph.push_back(*v);
                v = new vector<int>;
            } else {
                v->push_back(ch - 48);
            }
        }
    }
    graph.push_back(*v);
    fclose(f);
    return graph;
}

vector<tuple<int, int, int>> 
    Init_graph_Incidence_matrix(vector<vector<int>> m) {
    vector<tuple<int, int, int>> graph;
    int column_size = m.size();
    int string_size = m[1].size();
    int weight = 0, v1 = 0, v2 = 0;

    for (int i = 0; i < column_size; ++i) {
        for (int j = 0, k = 0; j < string_size && k < 2; ++j)
            if (m[i][j] != 0) {
                weight = m[i][j];
                if (k == 0)
                    v1 = j;
                else
                    v2 = j;
                k++;
            }
        graph.push_back(std::make_tuple(weight, v1, v2));
    }
    return graph;
}

vector<tuple<int, int, int>> 
    Init_graph_Adjacency_matrix(vector<vector<int>> m) {
    vector<tuple<int, int, int>> graph;
    int column_size = m.size();
    int string_size = m[1].size();

    for (int i = 0; i < column_size; ++i) {
        for (int j = i + 1; j < string_size; ++j)
            if (m[i][j] != 0)
                graph.push_back(std::make_tuple(m[i][j], i, j));
    }
    return graph;
}

void Graphviz(vector<tuple<int, int, int>> graph, 
              vector<tuple<int, int, int>> spanning_tree) {
    FILE* f = 
        fopen("C:/Users/HP/Desktop/tmp/infrastructure/Graphviz.txt", "w");
    if (f == 0)
        throw std::logic_error("Error! Can`t open the file!");

    int size_s_t = spanning_tree.size();
    int size_gr = graph.size();
    vector<bool> drawn(size_gr, false);

    fputs("graph {\n", f);
    for (int i = 0; i < size_s_t; ++i) {
        for (int j = 0; j < size_gr; ++j)
            if (spanning_tree[i] == graph[j])
                drawn[j] = true;
        fputc(get<1>(spanning_tree[i]) + 49, f);
        fputs("--", f);
        fputc(get<2>(spanning_tree[i]) + 49, f);
        fputs("[color = dodgerblue2, style = \"bold\", label=\"", f);
        fputc(get<0>(spanning_tree[i]) + 48, f);
        fputs("\"]\n", f);
    }

    for (int i = 0; i < size_gr; ++i) {
        if (drawn[i]) continue;
        fputc(std::get<1>(graph[i]) + 49, f);
        fputs("--", f);
        fputc(std::get<2>(graph[i]) + 49, f);
        fputs("[color = black, label=\"", f);
        fputc(std::get<0>(graph[i]) + 48, f);
        fputs("\"]\n", f);
    }
    fputs("}\n", f);
    fclose(f);
}
