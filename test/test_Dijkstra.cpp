#include <gtest/gtest.h>
#include "Dijkstra.h"

TEST(Dijkstra, NULL_Graph) {
    std::vector <std::vector <std::pair <int, int > > > v;
    ASSERT_ANY_THROW(Dijkstra(v, 0));
}

TEST(Dijkstra, Graph_With_One_Vertex) {
    std::vector <std::vector <std::pair <int, int > > > v(1);
    std::vector<int> result = Dijkstra(v, 0);
    EXPECT_EQ(result[0], 0);
}

TEST(Dijkstra, Easy_Graph) {
    std::vector <std::vector <std::pair <int, int> > > v(7);
    v[0].push_back(std::make_pair(1, 7));
    v[0].push_back(std::make_pair(2, 6));
    v[1].push_back(std::make_pair(0, 7));
    v[1].push_back(std::make_pair(2, 2));
    v[1].push_back(std::make_pair(3, 5));
    v[2].push_back(std::make_pair(0, 6));
    v[2].push_back(std::make_pair(1, 2));
    v[2].push_back(std::make_pair(3, 4));
    v[2].push_back(std::make_pair(4, 5));
    v[3].push_back(std::make_pair(1, 5));
    v[3].push_back(std::make_pair(2, 4));
    v[3].push_back(std::make_pair(4, 3));
    v[4].push_back(std::make_pair(2, 5));
    v[4].push_back(std::make_pair(3, 3));

    std::vector<int> result = Dijkstra(v, 0);
    EXPECT_EQ(result[3], 10);
    EXPECT_EQ(result[4], 11);
}

TEST(Dijkstra, Hard_Graph) {
    std::vector <std::vector <std::pair <int, int> > > v(7);
    v[0].push_back(std::make_pair(1, 7));
    v[0].push_back(std::make_pair(4, 4));
    v[0].push_back(std::make_pair(5, 6));
    v[1].push_back(std::make_pair(2, 5));
    v[2].push_back(std::make_pair(3, 3));
    v[3].push_back(std::make_pair(4, 1));
    v[3].push_back(std::make_pair(6, 4));
    v[3].push_back(std::make_pair(2, 3));
    v[4].push_back(std::make_pair(3, 1));
    v[5].push_back(std::make_pair(4, 3));
    v[5].push_back(std::make_pair(6, 2));

    std::vector<int> result = Dijkstra(v, 0);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 8);
    EXPECT_EQ(result[4], 4);
    EXPECT_EQ(result[5], 6);
    EXPECT_EQ(result[6], 8);
}
