#include <gtest/gtest.h>
#include <time.h>
#include <vector>
#include <tuple>

using std::vector;

vector<vector<int>> Create_adjacency_matrix(int size) {
    srand((unsigned)time(NULL));
    vector<vector<int>> m(size);
    for (int i = 0; i < size; ++i)
        m[i] = vector<int>(size, 0);
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j) {
            m[i][j] = (1 + rand() % 4) * (rand() % 4);
            m[j][i] = m[i][j];
        }
    return m;
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
