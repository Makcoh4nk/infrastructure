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
    int MinSon(int index_parent);

 public:
    void InsertElem(T e);
    void DeleteMin();
    T GetMin();

    bool IsEmpty() {
        return array.empty();
    }

    int GetSize() {
        return array.size();
    }

    T operator[](int index) {
        return array[index];
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
int Five_Heap<T>::MinSon(int index_parent) {
    int i = 0;
    int index = 0;
    int size = array.size();

    if (5 * index_parent + 1 < size) {
        i = 5 * index_parent + 1;
    } else {
        return -1;
    }

    index = i;
    while (i + 1 < size && i <= 5 * index_parent + 5) {
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
    int index_min_son = MinSon(0);
    int size = array.size();
    while ((index_min_son >= 0) && (index_min_son + 1 <= size)
        && (array[parent] > array[index_min_son])) {
        tmp = array[index_min_son];
        array[index_min_son] = array[parent];
        array[parent] = tmp;
        parent = index_min_son;
        index_min_son = MinSon(parent);
    }
}

template <typename T>
void Five_Heap<T>::DeleteMin() {
    if (GetSize() != 0) {
        array[0] = array[array.size() - 1];
        array.pop_back();
        ShiftDown();
    } else {
        throw std::logic_error("Out of range");
    }
}

template <typename T>
T Five_Heap<T>::GetMin() {
    if (static_cast<int>(array.size()) != 0) {
        return array[0];
    } else {
        throw  std::logic_error("Out of range");
    }
}

#endif  // INCLUDE_5_HEAP_H_
