#ifndef DIJKSTRA
#define DIJKSTRA

#include <queue>
#include "Graph.hpp"

#define infinity

class Dijkstra
{
public:
    Dijkstra() {}
    ~Dijkstra() {}

public:
    // vai servir para organizar a heap, apenas (predecessor, vertice, peso)
    void PathFind(Graph *g, const int start, int *d)
    {
    }
};

#endif