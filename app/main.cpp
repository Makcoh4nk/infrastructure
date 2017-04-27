#include "Islands.h"

int main() {
    srand((unsigned)time(NULL));
    for (int k = 0; k < 10; ++k) {
        int count_1 = 3 + rand() % 10;
        int count_2 = 3 + rand() % 10;
        int flag = 0;

        bool **m = new bool*[count_1];
        for (int i = 0; i < count_1; ++i)
            m[i] = new bool[count_2];

        for (int i = 0; i < count_1; ++i)
            for (int j = 0; j < count_2; ++j)
                m[i][j] = 0;

        while (flag < (count_1*count_2) / 4) {
            m[rand() % count_1][rand() % count_2] = 1;
            flag++;
        }

        for (int i = 0; i < count_1; ++i) {
            cout << ' ' << endl;
            for (int j = 0; j < count_2; ++j)
                cout << ' ' << m[i][j];
        }
        cout << endl << endl;
    }
}
