#ifndef INCLUDE_DIJKSTRA_H_
#define INCLUDE_DIJKSTRA_H_

#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#define INF 10000000

std::vector<int> Dijkstra(std::vector <std::vector <std::pair <int, int > > > v, int start);

#endif  // INCLUDE_DIJCSTRA_H_
