#ifndef INCLUDE_TREE_FROM_ARRAY_H_
#define INCLUDE_TREE_FROM_ARRAY_H_

#include <stdio.h>
#include <stack>
#include <queue>
#include <time.h>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct CNode {
    int data;
    CNode *left;
    CNode *right;
};

void Init_tree(CNode **tree, int *ar, int size_ar);
CNode *Add_leaf(CNode *root, int val);
void Print_tree(CNode *tree);

#endif  // INCLUDE_TREE_FROM_ARRAY_H_
