#include <Visual.h>

void vis_graph_mi(vector<vector<int>> graph, vector<vector<int>> ostov) {
    FILE* fp;
    fopen_s(&fp,"C:\\Users\\%username%\\Desktop\\graph1.gv", "w");

    fprintf(fp, "graph ostov {\n");
    fprintf(fp, "\tnode[shape=circle];\n");
    fprintf(fp, "\tedge[color=red];\n");
    vector <tuple<int, int, int>> edge_ostov;
    for (unsigned int i = 0; i < ostov.size(); ++i) {
        tuple<int, int, int> a = EDGE(ostov[i]);
        edge_ostov.push_back(a);
    }

    for (auto it = edge_ostov.begin(); it < edge_ostov.end(); ++it) {
        fprintf(fp, "\tedge[label=%d];\n", std::get<0>((*it)));
        fprintf(fp, "\t%d -- %d;\n", std::get<1>((*it)), std::get<2>((*it)));
    }

    fprintf(fp, "\tnode[shape=circle];\n");
    fprintf(fp, "\tedge[color=blue];\n");

    vector <tuple<int, int, int>> edge_ishod;
    for (auto it = graph.begin(); it < graph.end(); ++it) {
        bool flag = false;
        tuple<int, int, int> a = EDGE(*it);
        for (auto it1 = edge_ostov.begin(); it1 < edge_ostov.end(); ++it1) {
            if ((*it1) == a) {
                flag = true;
            }
        }
        if (flag == false) {
            edge_ishod.push_back(a);
        }
    }
    for (auto it = edge_ishod.begin(); it < edge_ishod.end(); it++) {
        fprintf(fp, "\tedge[label=%d];\n", std::get<0>((*it)));
        fprintf(fp, "\t%d -- %d;\n", std::get<1>((*it)), std::get<2>((*it)));
    }
    fprintf(fp, "}");
    fclose(fp);
}

void  vis_graph_ms(vector<vector<int>> graph, vector<vector<int>> ostov) {
    FILE* fp;
    fopen_s(&fp, "C:\\Users\\%username%\\Desktop\\graph2.gv", "w");

    fprintf(fp, "graph ostov {\n");
    fprintf(fp, "\tnode[shape=circle];\n");
    fprintf(fp, "\tedge[color=red];\n");

    vector <tuple<int, int, int >> edge_ostov;

    for (unsigned int i = 0; i < ostov.size(); ++i) {
        for (unsigned int j = 0; j < ostov[i].size(); ++j) {
            if (ostov[i][j] != MAX && ostov[i][j] > 0) {
                edge_ostov.push_back(std::make_tuple(ostov[i][j], i, i + j));
            }
        }
    }

    for (auto it = edge_ostov.begin(); it < edge_ostov.end(); ++it) {
        fprintf(fp, "\tedge[label=%d];\n", std::get<0>((*it)));
        fprintf(fp, "\t%d -- %d;\n", std::get<1>((*it)), std::get<2>((*it)));
    }

    fprintf(fp, "\tnode[shape=circle];\n");
    fprintf(fp, "\tedge[color=blue];\n");

    vector <tuple<int, int, int>> edge_ishod;

    for (unsigned int i = 0; i < graph.size(); ++i) {
        for (unsigned int j = 0; j < graph[i].size(); ++j) {
            if (graph[i][j] != MAX && graph[i][j] > 0) {
                tuple<int, int, int> a = std::make_tuple(graph[i][j], i, i + j);
                bool flag = false;
                for (auto it = edge_ostov.begin(); it < edge_ostov.end(); ++it) {
                    if ((*it) == a) {
                        flag = true;
                    }
                }
                if (flag == false) {
                    edge_ishod.push_back(a);
                }
            }
        }
    }
    for (auto it = edge_ishod.begin(); it < edge_ishod.end(); it++) {
        fprintf(fp, "\tedge[label=%d];\n", std::get<0>((*it)));
        fprintf(fp, "\t%d -- %d;\n", std::get<1>((*it)), std::get<2>((*it)));
    }
    fprintf(fp, "}");
    fclose(fp);
}