#ifndef INCLUDE_PRIORITYQUEUE_H_
#define INCLUDE_PRIORITYQUEUE_H_

#include "6-Heap.h"
#include "RB_tree.h"

template <typename T>
class H_PriorityQueue : public Six_Heap<T> {
};

template <typename T>
class RB_PriorityQueue : public RB_tree<T> {
};

#endif  // INCLUDE_PRIORITYQUEUE_H_
