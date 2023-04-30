#ifndef TOPOLOGICAL_SORTING
#define TOPOLOGICAL_SORTING

#include "Graph.hpp"
#include <stack>
#include <iostream>

using namespace std;

#define visited true
#define unvisited false

class TopoSort
{
public:
    void TopSort(Graph *g, const int v, stack<int> &s)
    {
        g->SetMark(v, visited);
        for (int w = g->First(v); w < g->GetVertices(); w = g->Next(v, w))
            if (!g->GetMark(w))
                TopSort(g, w, s);
        s.push(v);
    }
};

#endif
