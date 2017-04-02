#include <gtest/gtest.h>
#include "SearchWay.h"

TEST(SearchWay, SuperTest) {
    for (int i = -50; i < 50; ++i)
        for (int j = -50; j < 50; ++j) {
            int x = 50 - i;
            int y = 50 - j;
            char* temp = SearchWay(x, y, i, j);
            int step = 1;
            for (int k = 0; temp[k] != '\0'; ++k) {
                if (temp[k] == 'S') {
                    y -= step;
                    step++;
                } else if (temp[k] == 'N') {
                    y += step;
                    step++;
                } else if (temp[k] == 'W') {
                    x -= step;
                    step++;
                } else if (temp[k] == 'E') {
                    x += step;
                    step++;
                }
        }
        EXPECT_EQ(x, i);
        EXPECT_EQ(y, j);
    }
}
