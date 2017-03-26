#include "Array.h"

int* Conversion(int* ar, int size) {
    if (size == 1) { return ar; }

    int *temp = new int[size];
    int mult = 1;
    
    for (int i = 0; i < size; ++i) {
        temp[i] = mult;
        mult *= ar[i];
    }

    mult = 1;
    for (int i = size - 1; i >= 0; --i) {
        temp[i] *= mult;
        mult *= ar[i];
    }
    return temp;
}
