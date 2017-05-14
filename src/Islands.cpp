#include "Islands.h"

using std::vector;
using std::queue;

int Find(vector<int> v, int a) {
    int res = a;
    while (v[res] != res) {
        res = v[res];
    }
    return res;
}

void Union(vector<int>* v1, vector<int>* v2, int a, int b) {
    int x = Find(*v1, a);
    int y = Find(*v1, b);
    if ((*v2)[x] > (*v2)[y]) {
        (*v1)[y] = x;
        (*v2)[x]++;
    } else {
        (*v1)[x] = y;
        (*v2)[y]++;
    }
}

void Percolation(vector<vector<int>>* m) {
    int M = (*m).size();
    int N = M*M + 4;
    int st = 0;
    int left = 1;
    int right = 2;
    int fin = M*M + 3;
    vector<int> a(N);
    vector<int> b(N, 1);

    for (int i = 0; i < N; i++)
        a[i] = i;
    for (int i = 0; i < M; ++i)
        if ((*m)[0][i] == 1)
            Union(&a, &b, st, i + 3);
    for (int i = 0; i < M; ++i)
        if ((*m)[i][0] == 1)
            Union(&a, &b, left, i*M + 3);
    for (int i = 0; i < M; ++i)
        if ((*m)[M - 1][i] == 1)
            Union(&a, &b, right, i*M + (M - 1) + 3);
    for (int i = 0; i < M - 1; ++i)
        if ((*m)[0][i] == 1 && (*m)[0][i + 1] == 1)
            Union(&a, &b, i + 3, i + 4);
    for (int i = 1; i < M; ++i) {
        for (int j = 0; j < M - 1; ++j) {
            if ((*m)[i][j] == 1 && (*m)[i][j + 1])
                Union(&a, &b, i*M + j + 3, i*M + j + 4);
            if ((*m)[i][j] == 1 && (*m)[i - 1][j])
                Union(&a, &b, i*M + j + 3, (i - 1)*M + j + 3);
        }
        if ((*m)[i - 1][M - 1] == 1 && (*m)[i][M - 1] == 1)
            Union(&a, &b, (i - 1)*M + M, i*M + M);
    }

    for (int i = 0; i < M; ++i)
        if ((*m)[M - 1][i] == 1)
            Union(&a, &b, fin, (M - 1)*M + i + 4);

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j) {
            int x = Find(a, i*M + 3 + j);
            int s = Find(a, st);
            int l = Find(a, left);
            int r = Find(a, right);
            int f = Find(a, fin);
            if (((x != s) && (x != l) && (x != r) && (x != f)) && ((*m)[i][j] == 1))
                (*m)[i][j] = 0;
        }
}

void Sinking_field(vector<vector<int>> m, vector<vector<int>>* field, crdnt v) {
    int size = m.size();
    queue<crdnt> q;
    q.push(v);
    (*field)[v.str][v.col] = 1;
    while (!q.empty()) {
        crdnt vertex = q.front();
        q.pop();
        if (vertex.str > 0) {
            if ((m[vertex.str - 1][vertex.col] == 1) &&
                ((*field)[vertex.str - 1][vertex.col] == INF)) {
                crdnt* tmp = new crdnt;
                tmp->str = (vertex.str - 1);
                tmp->col = (vertex.col);
                q.push(*tmp);
                (*field)[vertex.str - 1][vertex.col] =
                    (*field)[vertex.str][vertex.col] + 1;
            }
        }

        if (vertex.str < (size - 1)) {
            if ((m[vertex.str + 1][vertex.col] == 1) &&
                ((*field)[vertex.str + 1][vertex.col] == INF)) {
                crdnt* tmp = new crdnt;
                tmp->str = (vertex.str + 1);
                tmp->col = (vertex.col);
                q.push(*tmp);
                (*field)[vertex.str + 1][vertex.col] =
                    (*field)[vertex.str][vertex.col] + 1;
            }
        }

        if (vertex.col > 0) {
            if ((m[vertex.str][vertex.col - 1] == 1) &&
                ((*field)[vertex.str][vertex.col - 1] == INF)) {
                crdnt* tmp = new crdnt;
                tmp->str = (vertex.str);
                tmp->col = (vertex.col - 1);
                q.push(*tmp);
                (*field)[vertex.str][vertex.col - 1] =
                    (*field)[vertex.str][vertex.col] + 1;
            }
        }

        if (vertex.col < size - 1) {
            if ((m[vertex.str][vertex.col + 1] == 1) &&
                ((*field)[vertex.str][vertex.col + 1] == INF)) {
                crdnt* tmp = new crdnt;
                tmp->str = (vertex.str);
                tmp->col = (vertex.col + 1);
                q.push(*tmp);
                (*field)[vertex.str][vertex.col + 1] =
                    (*field)[vertex.str][vertex.col] + 1;
            }
        }
    }
}

void Sinking(vector<vector<int>>* m) {
    int size = (*m).size();
    vector<vector<int>> field(size, vector<int>(size, INF));
    crdnt v;
    v.col = 0;
    for (v.str = 0; v.str < size; ++v.str)
        if (((*m)[v.str][v.col]) == 1 && (field[v.str][v.col] == INF))
            Sinking_field((*m), &field, v);
    v.col = size - 1;
    for (v.str = 0; v.str < size; ++v.str)
        if (((*m)[v.str][v.col]) == 1 && (field[v.str][v.col] == INF))
            Sinking_field((*m), &field, v);
    v.str = 0;
    for (v.col = 0; v.col < size; ++v.col)
        if (((*m)[v.str][v.col]) == 1 && (field[v.str][v.col] == INF))
            Sinking_field((*m), &field, v);
    v.str = size - 1;
    for (v.col = 0; v.col < size; ++v.col)
        if (((*m)[v.str][v.col]) == 1 && (field[v.str][v.col] == INF))
            Sinking_field((*m), &field, v);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (field[i][j] == INF)
                (*m)[i][j] = 0;
}
