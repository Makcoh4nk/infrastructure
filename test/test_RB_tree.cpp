#include <gtest/gtest.h>
#include "RB_tree.h"

using std::pair;
using std::vector;

TEST(RB_tree, CanInsertInEmptyTree) {
    RB_tree <int> a;
    int v = 2;
    a.Insert(v);
    EXPECT_EQ(a.root->color, 0);
    EXPECT_TRUE(a.root->left == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(a.root->right == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(a.root->parent == nullptr);
    EXPECT_EQ(a.root->value, v);
}

TEST(RB_tree, CanInsertInNOTEmptyTree) {
    RB_tree <int> a;
    a.Insert(2);
    a.Insert(3);

    EXPECT_EQ(a.root->color, 0);
    EXPECT_TRUE(a.root->left == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(a.root->right != reinterpret_cast<RB_node<int>*>(NIL));

    EXPECT_EQ(a.root->right->color, 1);
    EXPECT_EQ(a.root->right->value, 3);

    EXPECT_TRUE(a.root->right->left == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(a.root->right->right == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_EQ(a.root->value, 2);
    EXPECT_TRUE(a.root->right->parent == a.root);
}

TEST(RB_tree, ThrowFindWhenTreeIsEmpty) {
    RB_tree < int > a;

    ASSERT_ANY_THROW(a.Find(7));
}

TEST(RB_tree, CanFindCorrectForValueInTree) {
    RB_node<int>* res;
    RB_tree<int> a;
    a.Insert(2);
    a.Insert(3);
    a.Insert(4);
    res = a.Find(3);

    EXPECT_EQ(res, a.root);
}

TEST(RB_tree, CanDeleteForValueInTree) {
    RB_node<int>* res;
    RB_tree<int> a;
    a.Insert(2);
    a.Insert(3);
    a.Insert(4);
    a.Insert(10);
    a.Insert(5);
    a.Insert(23);
    a.Insert(0);
    a.Insert(11);
    a.Delete(4);
    res = a.Find(4);

    EXPECT_EQ(res, nullptr);
}

TEST(RB_tree, ThrowWhenDeleteInEmptyTree) {
    RB_tree<int> a;

    ASSERT_ANY_THROW(a.Delete(6));
}

TEST(RB_tree, CanDeleteForAdressInTree) {
    RB_node<int>* res = nullptr;
    RB_tree<int> a;
    a.Insert(2);
    a.Insert(3);
    a.Insert(4);
    a.Delete(a.Find(3));
    res = a.Find(3);

    EXPECT_EQ(res, nullptr);
    EXPECT_EQ(a.root->value, 4);
    EXPECT_EQ(a.root->color, 0);
    EXPECT_TRUE(a.root->parent == nullptr);
    EXPECT_EQ(a.root->left->value, 2);
    EXPECT_EQ(a.root->left->color, 1);
    EXPECT_TRUE(a.root->left->right == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(a.root->left->left == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_EQ(a.root->value, 4);
    EXPECT_TRUE(a.root->right == reinterpret_cast<RB_node<int>*>(NIL));
}

TEST(RB_tree, CanCorrectDeleteMin) {
    RB_node<int>* res;
    RB_tree<int> a;
    a.Insert(2);
    a.Insert(3);
    a.Insert(4);
    a.Insert(9);
    a.Insert(8);
    a.Insert(1);
    a.Insert(16);
    a.Insert(5);
    a.DeleteMin();
    res = a.Find(1);

    EXPECT_EQ(res, nullptr);
}