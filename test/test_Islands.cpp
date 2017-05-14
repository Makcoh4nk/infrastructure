#include <gtest/gtest.h>
#include "Islands.h"

int const size = 9;

TEST(Islands_Percolation, All_on_the_place) {
    vector<vector<int>> v(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        v[i][0] = 1;
        v[i][size - 1] = 1;
    }

    for (int i = 1; i < size - 1; ++i) {
        v[0][i] = 1;
        v[size - 1][i] = 1;
    }

    vector<vector<int>> n = v;
    Percolation(&v);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            EXPECT_EQ(v[i][j], n[i][j]);
}

TEST(Islands_Percolation, All_is_sinking) {
    vector<vector<int>> v(size, vector<int>(size, 0));
    vector<vector<int>> n = v;

    for (int i = 1; i < size - 1; ++i)
        v[4][i] = 1;
    for (int i = 1; i < size - 1; ++i)
        v[i][4] = 1;

    Percolation(&v);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            EXPECT_EQ(v[i][j], n[i][j]);
}

TEST(Islands_Sinking, All_on_the_place) {
    vector<vector<int>> v(size, vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        v[i][0] = 1;
        v[i][size - 1] = 1;
    }

    for (int i = 1; i < size - 1; ++i) {
        v[0][i] = 1;
        v[size - 1][i] = 1;
    }

    vector<vector<int>> n = v;
    Sinking(&v);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            EXPECT_EQ(v[i][j], n[i][j]);
}

TEST(Islands_Sinking, All_is_sinking) {
    vector<vector<int>> v(size, vector<int>(size, 0));
    vector<vector<int>> n = v;

    for (int i = 1; i < size - 1; ++i)
        v[4][i] = 1;
    for (int i = 1; i < size - 1; ++i)
        v[i][4] = 1;

    Sinking(&v);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            EXPECT_EQ(v[i][j], n[i][j]);
}

TEST(Islands_Percolation, Correct_sinking) {
    vector<vector<int>> v(size + 1, vector<int>(size + 1, 0));

    v[0][0] = 1;
    v[5][0] = 1;
    v[0][5] = 1;
    v[5][5] = 1;
    v[2][2] = 1;
    v[2][3] = 1;
    v[3][2] = 1;
    v[2][3] = 1;

    vector<vector<int>> n = v;

    Percolation(&n);
    Sinking(&v);

    for (int i = 0; i < size + 1; ++i)
        for (int j = 0; j < size + 1; ++j)
            EXPECT_EQ(v[i][j], n[i][j]);
}
