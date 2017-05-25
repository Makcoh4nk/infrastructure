#include <gtest/gtest.h>
#include "RB_tree.h"

using std::pair;
using std::vector;

TEST(RB_tree, CanInsertInEmptyTree) {
    RB_tree <int> t;
    int v = 2;
    t.Insert(v);
    EXPECT_EQ(t.root->color, 0);
    EXPECT_TRUE(t.root->left == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(t.root->right == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(t.root->parent == nullptr);
    EXPECT_EQ(t.root->value, v);
}

TEST(RB_tree, CanInsertInNOTEmptyTree) {
    RB_tree <int> t;
    t.Insert(2);
    t.Insert(3);

    EXPECT_EQ(t.root->color, 0);
    EXPECT_TRUE(t.root->left == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(t.root->right != reinterpret_cast<RB_node<int>*>(NIL));

    EXPECT_EQ(t.root->right->color, 1);
    EXPECT_EQ(t.root->right->value, 3);

    EXPECT_TRUE(t.root->right->left == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(t.root->right->right == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_EQ(t.root->value, 2);
    EXPECT_TRUE(t.root->right->parent == t.root);
}

TEST(RB_tree, ThrowFindWhenTreeIsEmpty) {
    RB_tree <int> t;

    ASSERT_ANY_THROW(t.Find(7));
}

TEST(RB_tree, CanFindCorrectForValueInTree) {
    RB_node<int>* res;
    RB_tree<int> t;
    t.Insert(2);
    t.Insert(3);
    t.Insert(4);
    res = t.Find(3);

    EXPECT_EQ(res, t.root);
}

TEST(RB_tree, CanDeleteForValueInTree) {
    RB_node<int>* res;
    RB_tree<int> t;
    t.Insert(2);
    t.Insert(3);
    t.Insert(4);
    t.Insert(10);
    t.Insert(5);
    t.Insert(23);
    t.Insert(0);
    t.Insert(11);
    t.Delete(4);
    res = t.Find(4);

    EXPECT_EQ(res, nullptr);
}

TEST(RB_tree, ThrowWhenDeleteInEmptyTree) {
    RB_tree<int> t;

    ASSERT_ANY_THROW(t.Delete(6));
}

TEST(RB_tree, CanDeleteForAdressInTree) {
    RB_node<int>* res = nullptr;
    RB_tree<int> t;
    t.Insert(2);
    t.Insert(3);
    t.Insert(4);
    t.Delete(t.Find(3));
    res = t.Find(3);

    EXPECT_EQ(res, nullptr);
    EXPECT_EQ(t.root->value, 4);
    EXPECT_EQ(t.root->color, 0);
    EXPECT_TRUE(t.root->parent == nullptr);
    EXPECT_EQ(t.root->left->value, 2);
    EXPECT_EQ(t.root->left->color, 1);
    EXPECT_TRUE(t.root->left->right == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_TRUE(t.root->left->left == reinterpret_cast<RB_node<int>*>(NIL));
    EXPECT_EQ(t.root->value, 4);
    EXPECT_TRUE(t.root->right == reinterpret_cast<RB_node<int>*>(NIL));
}

TEST(RB_tree, CanCorrectDeleteMin) {
    RB_node<int>* res;
    RB_tree<int> t;
    t.Insert(2);
    t.Insert(3);
    t.Insert(4);
    t.Insert(9);
    t.Insert(8);
    t.Insert(1);
    t.Insert(16);
    t.Insert(5);
    t.DeleteMin();
    res = t.Find(1);

    EXPECT_EQ(res, nullptr);
}