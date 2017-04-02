#include "SearchWay.h"

int main() {
    char *act = SearchWay(0, 0, 4, 6);
    for (int i = 0; act[i] != '\0'; ++i)
        cout << act[i] << ' ';
    cout << endl;
    return 0;
}
