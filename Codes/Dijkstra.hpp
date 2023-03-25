#ifndef DIJKSTRA
#define DIJKSTRA

#include <queue>
#include "Graph.hpp"

#define infinity 9999999
#define noParent -1

using namespace std;

class Dijkstra
{
private:
    int *distance, *parent;

private:
    void Init(int size)
    {
        distance = new int[size];
        parent = new int[size];
    }

public:
    Dijkstra() {}
    ~Dijkstra()
    {
        delete[] distance;
        delete[] parent;
    }

public:
    // vai servir para organizar a heap, apenas (predecessor, vertice, peso)
    void PathFind(Graph *g, const int start, int *d)
    {
        for (int i = 0; i < g->Vertice(); i++)
        {
            distance[i] = infinity;
            parent[i] = noParent;
        }

        priority_queue<int> pq;
    }
};

#endif