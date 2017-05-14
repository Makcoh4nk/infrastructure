#include "RB_tree.h"
#include "6-Heap.h"
#include "Dijkstra.h"

#include <stdio.h>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Path to file: ";
    char path[100];
    cin >> path;
    FILE* fp = fopen(path, "r");
    if (fp == 0) {
        cout << "Incorrect input!\n";
        return 0;
    }

    vector <vector <pair< int, int> > > vec;
    bool flag = 0;
    int ch = 0;
    int i = 0;
    pair<int, int>* p = new pair<int, int>;
    vector<pair<int, int>>* v = new vector<pair<int, int>>;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch != ' ') {
            if (ch == '\n') {
                vec.push_back(*v);
                v = new vector<pair<int, int>>;
                i++;
            } else {
                if (!flag) {
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

    cout << "---------------------------" << endl
        << "1 - RBTREE\n2 - 6 - HEAP\nSelect algorithm : ";
    int select = 0;
    while (select < 1 || select > 2) {
        cin >> select;
        if (select < 1 || select > 2)
            cout << "Repeat input!\n";
    }

    cout << "Start vertex: ";
    int start_v;
    int size;
    cin >> start_v;
    if (select == 1) {
        vector<int> min_ways = Dijkstra_RB_tree(start_v, vec);
        cout << "\n---------------------------\n";
        cout << " Minimal way from vertex " << start_v << endl;
        size = min_ways.size();
        for (int i = 0; i < size; i++) {
            cout << " to " << i << ": " << min_ways[i] << endl;
        }
        cout << "---------------------------\n";

    } else {
        vector<int> min_ways = Dijkstra_Heap(start_v, vec);
        cout << "\n---------------------------\n";
        cout << " Minimal way from vertex " << start_v << endl;
        size = min_ways.size();
        for (int i = 0; i < size; i++) {
            cout << " to " << i << ": " << min_ways[i] << endl;
        }
        cout << "---------------------------\n";
    }
    cout << endl;
}
