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
private:
    stack<int> s;

public:
    TopoSort(Graph *g)
    {
        int n = g->GetVertices();
        for (int i = 0; i < n; i++)
        {
            g->SetMark(i, unvisited);
        }

        for (int i = 0; i < n; i++)
        {
            if (!g->GetMark(i))
                Sort(g, i);
        }
    }

    void Sort(Graph *g, const int v)
    {
        g->SetMark(v, visited);
        for (int w = g->First(v); w < g->GetVertices(); w = g->Next(v, w))
            if (!g->GetMark(w))
                Sort(g, w);
        s.push(v);
    }

    stack<int> GetStack() const { return s; }

    void Print()
    {
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

#endif
