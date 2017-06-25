#ifndef INCLUDE_6_HEAP_H_
#define INCLUDE_6_HEAP_H_

#include <vector>

using std::vector;

template <typename T>
class Six_Heap {
 private:
    vector<T> array;
    void ShiftUp(int index);
    void ShiftDown();
    int MinSon(int index_parent);

 public:
    void InsertElem(T e);
    void DeleteMin();
    T GetMin();
    T operator[](int index) { return array[index]; }
    bool IsEmpty() { return array.empty(); }
    int GetSize() { return array.size(); }
};

template <typename T>
void Six_Heap<T>::InsertElem(T e) {
    array.push_back(e);
    ShiftUp(array.size() - 1);
}

template <typename T>
void Six_Heap<T>::ShiftUp(int index) {
    T tmp;
    while (array[index] < array[(index - 1) / 6]) {
        tmp = array[index];
        array[index] = array[(index - 1) / 6];
        array[(index - 1) / 6] = tmp;
        index = (index - 1) / 6;
    }
}

template <typename T>
int Six_Heap<T>::MinSon(int index_parent) {
    int i = 0;
    int index = 0;

    if (6 * index_parent + 1 < static_cast<int>(array.size())) {
        i = 6 * index_parent + 1;
    } else {
        return -1;
    }

    index = i;
    while (i + 1 < static_cast<int>(array.size()) && i <= 6 * index_parent + 6) {
        if (array[index] > array[i + 1]) {
            index = i + 1;
        }
        i++;
    }
    return index;
}

template <typename T>
void Six_Heap<T>::ShiftDown() {
    T tmp;
    int parent = 0;
    int index_min_son = MinSon(0);
    while (index_min_son >= 0 && index_min_son <= static_cast<int>(array.size()) - 1
        && array[parent] > array[index_min_son]) {
        tmp = array[index_min_son];
        array[index_min_son] = array[parent];
        array[parent] = tmp;
        parent = index_min_son;
        index_min_son = MinSon(parent);
    }
}

template <typename T>
void Six_Heap<T>::DeleteMin() {
    if (GetSize() != 0) {
        array[0] = array[array.size() - 1];
        array.pop_back();
        ShiftDown();
    } else {
        throw 1;
    }
}

template <typename T>
T Six_Heap<T>::GetMin() {
    if (static_cast<int>(array.size()) == 0)
        throw 1;
    return array[0];
}

#endif  // INCLUDE_6_HEAP_H_
