#include <gtest/gtest.h>
#include "5-Heap.h"

TEST(Five_Heap, CanInsertElementIntoHeap) {
    Five_Heap<int> actual;
    vector<int> expect;

    actual.InsertElem(9);
    actual.InsertElem(6);
    actual.InsertElem(13);
    actual.InsertElem(2);
    actual.InsertElem(7);
    actual.InsertElem(12);
    actual.InsertElem(4);

    expect.push_back(2);
    expect.push_back(4);
    expect.push_back(13);
    expect.push_back(6);
    expect.push_back(7);
    expect.push_back(12);
    expect.push_back(9);

    for (int i = 0; i < 7; ++i)
        EXPECT_EQ(expect[i], actual[i]);
}

TEST(Five_Heap, CanGetCorrectMinElement) {
    Five_Heap<int> actual;

    actual.InsertElem(9);
    actual.InsertElem(6);
    actual.InsertElem(13);
    actual.InsertElem(2);
    actual.InsertElem(7);
    actual.InsertElem(12);
    actual.InsertElem(4);

    EXPECT_EQ(actual.GetMin(), 2);
}

TEST(Five_Heap, ThrowWhenUseGetMinForEmptyHeap) {
    Five_Heap<int> actual;
    ASSERT_ANY_THROW(actual.GetMin());
}

TEST(Five_Heap, CanDeleteMinElement) {
    Five_Heap<int> actual;
    vector<int> expect;

    expect.push_back(4);
    expect.push_back(9);
    expect.push_back(13);
    expect.push_back(6);
    expect.push_back(7);
    expect.push_back(12);

    actual.InsertElem(9);
    actual.InsertElem(6);
    actual.InsertElem(13);
    actual.InsertElem(2);
    actual.InsertElem(7);
    actual.InsertElem(12);
    actual.InsertElem(4);

    actual.DeleteMin();
    for (unsigned int i = 0; i < 6; ++i)
        EXPECT_EQ(expect[i], actual[i]);
}

TEST(Five_Heap, ThrowWhenUseDeleteMinForEmptyHeap) {
    Five_Heap<int> actual;
    ASSERT_ANY_THROW(actual.DeleteMin());
}

TEST(Five_Heap, CanCorrectGetSize) {
    Five_Heap< int> actual;
    vector<int> expect;

    actual.InsertElem(9);
    actual.InsertElem(6);
    actual.InsertElem(13);
    actual.InsertElem(2);
    actual.InsertElem(7);
    actual.InsertElem(12);
    actual.InsertElem(4);

    EXPECT_EQ(7, actual.GetSize());
}
