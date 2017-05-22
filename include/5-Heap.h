#ifndef INCLUDE_5_HEAP_H_
#define INCLUDE_5_HEAP_H_

#include <vector>

using std::vector;

template <typename T>
class Five_Heap {
private:
    vector<T> array;
    void ShiftUp(int index);
    void ShiftDown();
    int MinSoon(int index_parent);

public:
    void InsertElem(T e);
    void DeleteMin();
    T GetMin();
    T operator[](int index);

    bool IsEmpty() {
        return array.empty();
    }

    int Size() {
        return array.size();
    }
};


template <typename T>
void Five_Heap<T>::InsertElem(T e) {
    array.push_back(e);
    ShiftUp(array.size() - 1);
}

template <typename T>
void Five_Heap<T>::ShiftUp(int index) {
    T tmp;
    while (array[index] < array[(index - 1) / 5]) {
        tmp = array[index];
        array[index] = array[(index - 1) / 5];
        array[(index - 1) / 5] = tmp;
        index = (index - 1) / 5;
    }
}

template <typename T>
int Five_Heap<T>::MinSoon(int index_parent) {
    int i = 0;
    int index = 0;

    if (5 * index_parent + 1 < static_cast<int>(array.size())) {
        i = 5 * index_parent + 1;
    } else {
        return -1;
    }

    index = i;
    while (i + 1 < static_cast<int>(array.size()) && i <= 5 * index_parent + 5) {
        if (array[index] > array[i + 1]) {
            index = i + 1;
        }
        i++;
    }
    return index;
}

template <typename T>
void Five_Heap<T>::ShiftDown() {
    T tmp;
    int parent = 0;
    int index_min_soon = MinSoon(0);
    while (index_min_soon >= 0 && index_min_soon <= static_cast<int>(array.size()) - 1
        && array[parent] > array[index_min_soon]) {
        tmp = array[index_min_soon];
        array[index_min_soon] = array[parent];
        array[parent] = tmp;
        parent = index_min_soon;
        index_min_soon = MinSoon(parent);
    }
}

template <typename T>
void Five_Heap<T>::DeleteMin() {
    if (Size() != 0) {
        array[0] = array[array.size() - 1];
        array.pop_back();
        ShiftDown();
    } else {
        throw 1;
    }
}

template <typename T>
T Five_Heap<T>::GetMin() {
    if (static_cast<int>(array.size()) != 0) {
        return array[0];
    } else {
        throw 1;
    }
}

template <typename T>
T Five_Heap<T>::operator[](int index) {
    return array[index];
}

#endif  // INCLUDE_5_HEAP_H_
