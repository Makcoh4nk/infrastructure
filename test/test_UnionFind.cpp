#include <gtest/gtest.h>
#include "UnionFind.h"

TEST(Union_Find, CanInitArray) {
    UnionFind actual(5);
    int expect[5] = { 0, 1, 2, 3, 4 };
    for (int i = 0; i < 5; ++i)
        EXPECT_EQ(actual[i], expect[i]);
}

TEST(Union_Find, CanUnionTwoElements) {
    UnionFind uf(2);
    ASSERT_NO_THROW(uf.Union(0, 1));
}

TEST(Union_Find, CanFindParentOfElement) {
    UnionFind uf(10);
    uf.Union(2, 5);
    uf.Union(5, 1);
    uf.Union(1, 9);
    EXPECT_EQ(2, uf.Find(9));
}

TEST(Union_Find, ThrowIfElemOutOfRange_Union) {
    UnionFind uf(3);
    ASSERT_ANY_THROW(uf.Union(1, 5));
}

TEST(Union_Find, ThrowIfElemOutOfRange_Find) {
    UnionFind uf(3);
    ASSERT_ANY_THROW(uf.Find(5));
}
