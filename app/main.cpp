#include "Islands.h"

using std::cout;
using std::endl;

int main() {
    srand((unsigned)time(NULL));

    int count = 3 + rand() % 10;
    int temp = 0;

    vector<vector<int>> m(count, vector<int>(count, 0));

    while (temp < (count*count) / 4) {
        m[rand() % count][rand() % count] = 1;
        temp++;
    }


    cout << "Your map:";
    for (int i = 0; i < count; ++i) {
        cout << ' ' << endl;
        for (int j = 0; j < count; ++j)
            cout << ' ' << m[i][j];
    }
    cout << endl << endl;

    vector<vector<int>> m1 = m;
    vector<vector<int>> m2 = m;

    Percolation(&m1);
    Sinking(&m2);

    cout << endl << "RESULTS:\n\n";

    cout << "Percolation:";
    for (int i = 0; i < count; ++i) {
        cout << ' ' << endl;
        for (int j = 0; j < count; ++j)
            cout << ' ' << m1[i][j];
    }

    cout << "\n\nSinking:";
    for (int i = 0; i < count; ++i) {
        cout << ' ' << endl;
        for (int j = 0; j < count; ++j)
            cout << ' ' << m2[i][j];
    }
    cout << endl;
}
