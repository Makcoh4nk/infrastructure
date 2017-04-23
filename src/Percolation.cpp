#include <time.h>
#include <stdlib.h>
#include <vector>

int Find(std::vector<int> v, int x) {
    int tmp = x;
    while (v[tmp] != tmp)
        tmp = v[tmp];
    return tmp;
}

void Union(std::vector<int> *v1, std::vector<int> *v2, int x, int y) {
    if ((*v2)[Find(*v1, x)] > (*v2)[Find(*v1, y)]) {
        (*v1)[Find(*v1, y)] = (*v1)[Find(*v1, x)];
        (*v2)[Find(*v1, x)]++;
    } else {
        (*v1)[Find(*v1, x)] = (*v1)[Find(*v1, y)];
        (*v2)[Find(*v1, y)]++;
    }
}

bool Percolation(std::vector<std::vector<int>> v) {
    int mSize = v.size();
    int n = mSize*mSize + 2;
    std::vector<int> c(n);
    std::vector<int> d(n, 1);

    for (int i = 0; i < n; ++i)
        c[i] = i;
    for (int i = 0; i < mSize; ++i)
        if (v[0][i]) Union(&c, &d, 0, i + 1);
    for (int i = 0; i < mSize - 1; ++i) {
        for (int j = 0; j < mSize - 1; ++j) {
            if (v[i][j] && v[i][j + 1]) Union(&c, &d, i*mSize + j + 1,
                i*mSize + j + 2);
            if (v[i][j] && v[i + 1][j]) Union(&c, &d, i*mSize + j + 1,
                (i + 1)*mSize + j + 1);
        }

        if (v[i][mSize - 1] && v[i + 1][mSize - 1]) Union(&c, &d,
            i*mSize + mSize,
            (i + 1)*mSize + mSize);
    }

    for (int j = 0; j < mSize - 1; ++j)
        if (v[mSize - 1][j] && v[mSize - 1][j + 1]) Union(&c, &d,
            (mSize - 1)*mSize + j + 1,
            (mSize - 1)*mSize + j + 2);

    for (int j = 0; j < mSize; ++j)
        if (v[mSize - 1][j]) Union(&c, &d, n - 1, (mSize - 1)*mSize + j + 1);

    if (Find(c, 0) == Find(c, n - 1)) {
        return true;
    } else {
        return false;
    }
}

double Probability(int n, int k) {
    int x, y;
    srand((unsigned)time(NULL));
    double s = 0, j = 0;
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
    for (int i = 0; i < k; ++i) {
        for (j = 0; !Percolation(m); ++j) {
            x = rand() % n;
            y = rand() % n;
            if (m[x][y] == 1) {
                j--;
                continue;
            }
            m[x][y] = 1;
        }
        s += j / (n * n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                m[i][j] = 0;
    }
    return s / k;
}
