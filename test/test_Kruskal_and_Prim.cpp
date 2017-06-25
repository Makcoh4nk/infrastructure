#include <gtest/gtest.h>
#include "Kruskal_and_Prim.h"

using std::make_tuple;

TEST(Kruskal, CorrectAlgorithm) {
    vector<tuple<int, int, int>> graph;
    graph.push_back(make_tuple(5, 0, 1));
    graph.push_back(make_tuple(8, 0, 2));
    graph.push_back(make_tuple(9, 1, 5));
    graph.push_back(make_tuple(4, 2, 5));
    graph.push_back(make_tuple(2, 2, 6));
    graph.push_back(make_tuple(12, 1, 3));
    graph.push_back(make_tuple(6, 3, 5));
    graph.push_back(make_tuple(3, 3, 4));
    graph.push_back(make_tuple(8, 2, 4));
    graph.push_back(make_tuple(7, 4, 6));

    vector<tuple<int, int, int>> expect;
    expect.push_back(make_tuple(2, 2, 6));
    expect.push_back(make_tuple(3, 3, 4));
    expect.push_back(make_tuple(4, 2, 5));
    expect.push_back(make_tuple(5, 0, 1));
    expect.push_back(make_tuple(6, 3, 5));
    expect.push_back(make_tuple(8, 0, 2));

    vector<tuple<int, int, int>> spanning_tree = Kruskal(graph, 7);
    for (int i = 0; i < 6; ++i)
        EXPECT_EQ(spanning_tree[i], expect[i]);
}

TEST(Kruskal, ThrowIfGraphIsDisconnected) {
    vector<tuple<int, int, int>> graph;
    graph.push_back(make_tuple(4, 0, 1));
    graph.push_back(make_tuple(5, 2, 3));
    vector<tuple<int, int, int>> spanning_tree;
    ASSERT_ANY_THROW(spanning_tree = Kruskal(graph, 4));
}

TEST(Prim, CorrectAlgorithm) {
    vector<tuple<int, int, int>> graph;
    graph.push_back(make_tuple(5, 0, 1));
    graph.push_back(make_tuple(8, 0, 2));
    graph.push_back(make_tuple(9, 1, 5));
    graph.push_back(make_tuple(4, 2, 5));
    graph.push_back(make_tuple(2, 2, 6));
    graph.push_back(make_tuple(12, 1, 3));
    graph.push_back(make_tuple(6, 3, 5));
    graph.push_back(make_tuple(3, 3, 4));
    graph.push_back(make_tuple(8, 2, 4));
    graph.push_back(make_tuple(7, 4, 6));

    vector<tuple<int, int, int>> expect;
    expect.push_back(make_tuple(5, 0, 1));
    expect.push_back(make_tuple(8, 0, 2));
    expect.push_back(make_tuple(2, 2, 6));
    expect.push_back(make_tuple(4, 2, 5));
    expect.push_back(make_tuple(6, 3, 5));
    expect.push_back(make_tuple(3, 3, 4));

    vector<tuple<int, int, int>> spanning_tree = Prim(graph, 7);
    for (int i = 0; i < 6; ++i)
        EXPECT_EQ(spanning_tree[i], expect[i]);
}

TEST(Prim, ThrowIfGraphIsDisconnected) {
    vector<tuple<int, int, int>> graph;
    graph.push_back(make_tuple(4, 0, 1));
    graph.push_back(make_tuple(5, 2, 3));
    vector<tuple<int, int, int>> spanning_tree;
    ASSERT_ANY_THROW(spanning_tree = Prim(graph, 4));
}
