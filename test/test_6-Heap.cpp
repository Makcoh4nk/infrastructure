#include <gtest/gtest.h>
#include "6-Heap.h"

TEST(Six_Heap, CanInseartElInHeap) {
    Six_Heap< int> a;
    vector<int> res;

    res.push_back(4);
    res.push_back(7);
    res.push_back(10);
    res.push_back(9);
    res.push_back(11);
    res.push_back(12);
    res.push_back(8);
    res.push_back(13);

    a.InsertElem(10);
    a.InsertElem(13);
    a.InsertElem(9);
    a.InsertElem(8);
    a.InsertElem(11);
    a.InsertElem(12);
    a.InsertElem(4);
    a.InsertElem(7);

    for (unsigned int i = 0; i < res.size(); ++i)
        EXPECT_EQ(res[i], a[i]);
}

TEST(Six_Heap, CanDeleteMinEl) {
    Six_Heap<int> a;
    vector<int> res;

    res.push_back(7);
    res.push_back(13);
    res.push_back(10);
    res.push_back(9);
    res.push_back(11);
    res.push_back(12);
    res.push_back(8);

    a.InsertElem(10);
    a.InsertElem(13);
    a.InsertElem(9);
    a.InsertElem(8);
    a.InsertElem(11);
    a.InsertElem(12);
    a.InsertElem(4);
    a.InsertElem(7);
    a.DeleteMin();

    for (unsigned int i = 0; i < res.size(); ++i)
        EXPECT_EQ(res[i], a[i]);
}



TEST(Six_Heap, ThrowWhenGetMinInEmptyHeap) {
    Six_Heap<int> a;
    ASSERT_ANY_THROW(a.GetMin());
}

TEST(Six_Heap, CanGetCorrectMinElement) {
    Six_Heap<int> a;
    a.InsertElem(10);
    a.InsertElem(13);
    a.InsertElem(9);
    a.InsertElem(8);
    a.InsertElem(11);
    a.InsertElem(12);
    a.InsertElem(4);
    a.InsertElem(7);

    EXPECT_EQ(a.GetMin(), 4);
}

TEST(Six_Heap, ThrowWhenDeleteMinElementInEmpty) {
    Six_Heap<int> a;

    ASSERT_ANY_THROW(a.DeleteMin());
}

TEST(Six_Heap, CanCorrectGetSize) {
    Six_Heap< int> a;
    vector<int> res;

    a.InsertElem(10);
    a.InsertElem(13);
    a.InsertElem(9);
    a.InsertElem(8);
    a.InsertElem(11);
    a.InsertElem(12);
    a.InsertElem(4);
    a.InsertElem(7);

    EXPECT_EQ(8, a.Size());
}