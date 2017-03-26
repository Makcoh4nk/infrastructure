#include <gtest/gtest.h>
#include "Tree_from_Array.h"

int height(CNode *tree) {
    CNode *temp = tree;
    int h1 = 0, h2 = 0;
    if (tree == NULL) return 0;
    if (tree->left) { h1 = height(tree->left); }
    if (tree->right) { h2 = height(tree->right); }
    if (h1 > h2) {
        return h1 + 1;
    } else {
        return h2 + 1;
    }
}

TEST(CreateTree, CanCreateEmptyTree) {
    int ar[1] = { 1 };
    CNode* tree = 0;
    EXPECT_NO_THROW(Init_tree(&tree, ar, 1));
}

TEST(InitTree, Correct_Init_Tree_2_Elem) {
    int ar[2] = { 2, 8 };
    CNode* tree = 0;
    Init_tree(&tree, ar, 2);
    EXPECT_EQ(tree->data, 8);
    EXPECT_EQ(tree->left->data, 2);
}

TEST(InitTree, Correct_Height_Tree_2_Elem) {
    int ar[2] = { 2, 8 };
    CNode* tree = 0;
    Init_tree(&tree, ar, 2);
    EXPECT_EQ(height(tree), 2);
}

TEST(InitTree, Correct_Init_Tree_5_Elem) {
    int ar[5] = { 1, 3, 4, 7, 10 };
    CNode* tree = 0;
    Init_tree(&tree, ar, 5);
    EXPECT_EQ(tree->data, 4);
    EXPECT_EQ(tree->left->data, 3);
    EXPECT_EQ(tree->left->left->data, 1);
    EXPECT_EQ(tree->right->data, 10);
    EXPECT_EQ(tree->right->left->data, 7);
}

TEST(InitTree, Correct_Height_Tree_5_Elem) {
    int ar[5] = { 1, 3, 4, 7, 10 };
    CNode* tree = 0;
    Init_tree(&tree, ar, 5);
    EXPECT_EQ(height(tree), 3);
}
