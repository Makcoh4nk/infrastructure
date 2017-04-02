#include "SearchWay.h"

char* SearchWay(int x0, int y0, int x, int y) {
    char *way = new char[1000];
    int step = 1;
    int act_x = x0;
    int act_y = y0;
    int i = 0;

    if ((act_x == x) && (act_y == y)) {
        way[i] = '\0';
        return way;
    }

    do {
        if (act_x > x) {
            act_x += step;
            way[i++] = 'E';
            step++;
            act_x -= step;
            way[i++] = 'W';
        } else {
            act_x -= step;
            way[i++] = 'W';
            step++;
            act_x += step;
            way[i++] = 'E';
        }
    } while (act_x != x);

    do {
        if (act_y > y) {
            act_y += step;
            way[i++] = 'N';
            step++;
            act_y -= step;
            way[i++] = 'S';
        } else {
            act_y -= step;
            way[i++] = 'S';
            step++;
            act_y += step;
            way[i++] = 'N';
        }
    } while (act_y != y);

    way[i] = '\0';
    return way;
}

/*bool ExistsSimpleWay(int act_x, int act_y, int x, int y, int step) {
    int temp = 0;
    while ( temp < (abs(x - act_x) + abs(y - act_y))) {
        temp += step;
        step++;
    }
    if (temp > (abs(x - act_x) + abs(y - act_y))) { return 0; }
    return 1;
}*/
