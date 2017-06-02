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
    FILE* fp = fopen(path, "r");
    if (fp == 0) {
        cout << "File can't be opened!\n\n";
        return 0;
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
                        p->first = ch - 49;
                        flag = 1;
                    } else {
                        p->second = ch - 48;
                        flag = 0;
                        v->push_back(*p);
                        p = new pair<int, int>;
                    }
                }
            }
        }

        cout << "---------------------------\n"
            << "1 - RED-BLACK TREE\n2 - 6 - HEAP\nWhich algorithm do you want to use?: ";
        int select = 1;
        while (select < 1 || select > 2) {
    //      cin >> select;
            if (select < 1 || select > 2)
                cout << "Select 1 or 2 algorithm: ";
        }

        int start_v = 1;
        int size = vec.size() + 1;
        do {
            cout << "\nThe graph has the following vertices:\n";
            for (int i = 1; i < size; ++i)
                cout << i << ' ';
            cout << "\nSelect start vertex: ";
//          cin >> start_v;
            if (start_v < 1 || start_v > size) {
                cout << "Vertex doesn't exist!\nPlease repeat input\n";
            }
        } while (start_v < 1 || start_v > size);

        start_v--;
        vector<int> min_ways;
        if (select == 1)
            min_ways = Dijkstra_RB_tree(start_v, vec);
        else
            min_ways = Dijkstra_Six_Heap(start_v, vec);

        cout << "\n---------------------------\n";
        cout << " Minimal ways:\n";
        size = min_ways.size();
        for (int i = 0; i < size; ++i) {
            if (i != start_v) {
                cout << ' ' << start_v + 1 << " --> " << i + 1 << ": ";
                    if (min_ways[i] != MAX)
                        cout << min_ways[i] << endl;
                    else
                        cout << "Way doesn't exist!\n";
            }
        }
        cout << "---------------------------\n\n";
    }
}
