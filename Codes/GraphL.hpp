#ifndef ADJACENCY_GRAPH
#define ADJACENCY_GRAPH

#include "Graph.hpp"
#include "Edge.hpp"
#include <list>

#define visited true
#define unvisited false

using namespace std;

template <typename T>
class GraphL : Graph<T>
{
public:
    int numVertex, numEdge;
    bool *mark;
    list<list<Edge<T>>> adj;

public:
    GraphL(int nVertex)
    {
        Init(nVertex);
    }
    ~GraphL()
    {
        delete[] mark;
    }

public:
    void Init(const int n) override
    {
        numVertex = n;
        numEdge = 0;

        mark = new bool[numVertex];
        for (int i = 0; i < numVertex; i++)
            mark[i] = unvisited;

        adj = new list<Edge<T>>[numVertex];
    }
    const int GetVertices() const override { return numVertex; }
    const int GetEdges() const override { return numEdge; }
    const T First(int v) const override {}
    const T Next(int v, int w) const override {}
    void SetEdge(const int i, const int j, int weight) override {}
    void DelEdge(int v1, int v2) override {}
    bool IsEdge(int i, int j) override { return false; }
    int Weight(int v1, int v2) override
    {
        int weight = IsEdge(v1, v2) ? adj[v1][v2].Weight() : Infinity<T>::value;
        return weight;
    }
    bool GetMark(int v) override { return mark[v]; }
    void SetMark(int v, bool val) override { mark[v] = val; }
};

#endif