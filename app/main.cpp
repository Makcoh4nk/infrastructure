#include "RB_tree.h"
#include "6-Heap.h"
#include "Dijkstra.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Path to file: ";
    char path[300];
    cin >> path;
    FILE* fp;
    fopen_s(&fp, path, "r");
    if (fp == 0) {
        cout << "File cannot be opened!\n\n";
    } else {
        vector <vector <pair <int, int> > > vec;
        bool flag = 0;
        int ch = 0;
        pair<int, int>* p = new pair<int, int>;
        vector<pair<int, int>>* v = new vector<pair<int, int>>;

       while ((ch = fgetc(fp)) != EOF) {
            if (ch != ' ') {
                if (ch == '\n') {
                    vec.push_back(*v);
                    v = new vector<pair<int, int>>;
                } else {
                    if (flag == 0) {
                        p->second = ch - 48;
                        flag = 1;
                    } else {
                        p->first = ch - 48;
                        flag = 0;
                        v->push_back(*p);
                        p = new pair<int, int>;
                    }
                }
            }
        }

        cout << "---------------------------\n"
            << "1 - RED-BLACK TREE\n2 - 6 - HEAP\nWhich algorithm do you want to use?: ";
        int select = 0;
        while (select < 1 || select > 2) {
            cin >> select;
            if (select < 1 || select > 2)
                cout << "Incorrect input! Please repeat input:";
        }

        cout << "Start vertex: ";
        int start_v;
        cin >> start_v;
        vector<int> min_ways;

        if (select == 1) 
            min_ways = Dijkstra_RB_tree(start_v, vec);
        else 
            min_ways = Dijkstra_Six_Heap(start_v, vec);

        cout << "\n---------------------------\n";
        cout << " Minimal way from vertex " << start_v << endl;
        int size = min_ways.size();
        for (int i = 0; i < size; ++i) {
            cout << " to " << i << ": " << min_ways[i] << endl;
        }
        cout << "---------------------------\n\n";
    }
    return 0;
}
