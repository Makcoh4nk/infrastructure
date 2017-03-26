#include "Array.h"

int main() {
    int temp[5] = { 1, 2, 3, 4, 5 };
    int *act = Conversion(temp, 5);

    for (int i = 0; i < 5; ++i)
        cout << temp[i] << ' ';
    cout << endl;

    for (int i = 0; i < 5; ++i)
        cout << act[i] << ' ';
    cout << endl;
}
