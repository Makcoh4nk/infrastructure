#include <gtest/gtest.h>
#include "6-Heap.h"

TEST(Six_Heap, CanInseartElInHeap) {
    Six_Heap<int> h;
    vector<int> res;

    res.push_back(4);
    res.push_back(7);
    res.push_back(10);
    res.push_back(9);
    res.push_back(11);
    res.push_back(12);
    res.push_back(8);
    res.push_back(13);

    h.InsertElem(10);
    h.InsertElem(13);
    h.InsertElem(9);
    h.InsertElem(8);
    h.InsertElem(11);
    h.InsertElem(12);
    h.InsertElem(4);
    h.InsertElem(7);

    for (unsigned int i = 0; i < res.size(); ++i)
        EXPECT_EQ(res[i], h[i]);
}

TEST(Six_Heap, CanDeleteMinEl) {
    Six_Heap<int> h;
    vector<int> res;

    res.push_back(7);
    res.push_back(13);
    res.push_back(10);
    res.push_back(9);
    res.push_back(11);
    res.push_back(12);
    res.push_back(8);

    h.InsertElem(10);
    h.InsertElem(13);
    h.InsertElem(9);
    h.InsertElem(8);
    h.InsertElem(11);
    h.InsertElem(12);
    h.InsertElem(4);
    h.InsertElem(7);
    h.DeleteMin();

    for (unsigned int i = 0; i < res.size(); ++i)
        EXPECT_EQ(res[i], h[i]);
}



TEST(Six_Heap, ThrowWhenGetMinInEmptyHeap) {
    Six_Heap<int> h;
    ASSERT_ANY_THROW(h.GetMin());
}

TEST(Six_Heap, CanGetCorrectMinElement) {
    Six_Heap<int> h;
    h.InsertElem(10);
    h.InsertElem(13);
    h.InsertElem(9);
    h.InsertElem(8);
    h.InsertElem(11);
    h.InsertElem(12);
    h.InsertElem(4);
    h.InsertElem(7);

    EXPECT_EQ(h.GetMin(), 4);
}

TEST(Six_Heap, ThrowWhenDeleteMinElementInEmpty) {
    Six_Heap<int> h;

    ASSERT_ANY_THROW(h.DeleteMin());
}

TEST(Six_Heap, CanCorrectGetSize) {
    Six_Heap< int> h;
    vector<int> res;

    h.InsertElem(10);
    h.InsertElem(13);
    h.InsertElem(9);
    h.InsertElem(8);
    h.InsertElem(11);
    h.InsertElem(12);
    h.InsertElem(4);
    h.InsertElem(7);

    EXPECT_EQ(8, h.Size());
}