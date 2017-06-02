#include <gtest/gtest.h>
#include "6-Heap.h"

TEST(Six_Heap, CanInsertElementIntoHeap) {
    Six_Heap<int> actual;
    vector<int> expect;

    expect.push_back(1);
    expect.push_back(13);
    expect.push_back(7);
    expect.push_back(6);
    expect.push_back(2);
    expect.push_back(10);
    expect.push_back(9);

    actual.InsertElem(13);
    actual.InsertElem(1);
    actual.InsertElem(7);
    actual.InsertElem(6);
    actual.InsertElem(2);
    actual.InsertElem(10);
    actual.InsertElem(9);

    for (unsigned int i = 0; i < expect.size(); ++i)
        EXPECT_EQ(expect[i], actual[i]);
}

TEST(Six_Heap, CanDeleteMinElement) {
    Six_Heap<int> actual;
    vector<int> expect;

    expect.push_back(7);
    expect.push_back(13);
    expect.push_back(10);
    expect.push_back(9);
    expect.push_back(11);
    expect.push_back(12);
    expect.push_back(8);

    actual.InsertElem(10);
    actual.InsertElem(13);
    actual.InsertElem(9);
    actual.InsertElem(8);
    actual.InsertElem(11);
    actual.InsertElem(12);
    actual.InsertElem(4);
    actual.InsertElem(7);
    actual.DeleteMin();

    for (unsigned int i = 0; i < expect.size(); ++i)
        EXPECT_EQ(expect[i], actual[i]);
}


TEST(Six_Heap, ThrowWhenTryingToGetMinInEmptyHeap) {
    Six_Heap<int> actual;
    ASSERT_ANY_THROW(actual.GetMin());
}


TEST(Six_Heap, ThrowWhenDeleteMinElementInEmpty) {
    Six_Heap<int> actual;

    ASSERT_ANY_THROW(actual.DeleteMin());
}

TEST(Six_Heap, CanGetCorrectMinElement) {
    Six_Heap<int> actual;
    actual.InsertElem(10);
    actual.InsertElem(13);
    actual.InsertElem(9);
    actual.InsertElem(8);
    actual.InsertElem(11);
    actual.InsertElem(12);
    actual.InsertElem(4);
    actual.InsertElem(7);

    EXPECT_EQ(actual.GetMin(), 4);
}

TEST(Six_Heap, CanCorrectGetSize) {
    Six_Heap< int> actual;
    vector<int> expect;

    actual.InsertElem(10);
    actual.InsertElem(13);
    actual.InsertElem(9);
    actual.InsertElem(8);
    actual.InsertElem(11);
    actual.InsertElem(12);
    actual.InsertElem(4);
    actual.InsertElem(7);

    EXPECT_EQ(8, actual.Size());
}
