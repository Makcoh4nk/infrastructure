#include <gtest/gtest.h>
#include "Dijkstra.h"

using std::vector;
using std::make_pair;

vector< vector< std::pair< int, int > > > InitTestGraph() {
    vector< vector< std::pair< int, int > > > test(7);
    auto it = test.begin();
    it->push_back(make_pair(4, 1));
    it->push_back(make_pair(6, 2));
    it++;
    it->push_back(make_pair(1, 3));
    it++;
    it->push_back(make_pair(3, 3));
    it->push_back(make_pair(2, 4));
    it++;
    it->push_back(make_pair(1, 5));
    it++;
    it->push_back(make_pair(4, 6));
    it->push_back(make_pair(1, 5));
    it++;
    it->push_back(make_pair(2, 6));
    return test;
}

TEST(Dijkstra, correct_algorithm_HEAP) {
    auto graph = InitTestGraph();
    vector<int> expect_ways = { 0, 4, 6, 5, 8, 6, 8 };
    vector<int> actual_ways = Dijkstra_Six_Heap(0, graph);
    EXPECT_EQ(actual_ways, expect_ways);
}

TEST(Dijkstra, correct_algorithm_TREE) {
    auto graph = InitTestGraph();
    vector<int> expect_ways = { 0,  4, 6, 5, 8, 6, 8 };
    vector<int> actual_ways = Dijkstra_RB_tree(0, graph);
    EXPECT_EQ(actual_ways, expect_ways);
}
