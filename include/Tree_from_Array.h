#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <stdio.h>
#include <queue>
#include <iostream>

#define size_t 5

using std::cout;
using std::cin;
using std::endl;

struct Branch {
	int data;
	Branch *left;
	Branch *right;
};

void Init_tree(Branch **tree, int ar[size_t]);
Branch *Add_leaf(Branch *root, int val);
void Print_tree(Branch *tree);

#endif  // INCLUDE_TREE_H_
