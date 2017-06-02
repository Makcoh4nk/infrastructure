#ifndef INCLUDE_PRIORITYQUEUE_H_
#define INCLUDE_PRIORITYQUEUE_H_

#include "6-Heap.h"
#include "RB_tree.h"

template <typename T>
class PriorityQueue_on_RBT : public RB_tree<T> {
public:
};

template <typename T>
class PriorityQueue_on_HEAP: public Six_Heap<T> {
 public:
};

#endif  // INCLUDE_PRIORITYQUEUE_H_
