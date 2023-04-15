#ifndef EDGE_ADJACENCY_LIST_GRAPH
#define EDGE_ADJACENCY_LIST_GRAPH

#include "BaseEdge.hpp"

class Edge : public BaseEdge
{
public:
    Edge(int v, int w)
    {
        vertex = v;
        wt = w;
    }
};

#endif