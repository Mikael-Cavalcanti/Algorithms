#ifndef ADJACENCY_GRAPH
#define ADJACENCY_GRAPH

#include "Graph.hpp"
#include "Edge.hpp"
#include <list>

#define visited true
#define unvisited false

using namespace std;

template <typename T>
class GraphL
{
public:
    int numVertex, numEdge;
    bool *mark;
    list<Edge<T>> *adj;

public:
    GraphL(int nVertex)
    {
        numVertex = nVertex;
        numEdge = 0;

        mark = new bool[numVertex];
        for (int i = 0; i < numVertex; i++)
            mark[i] = unvisited;

        adj = new list<Edge<T>>[numVertex];
    }
    ~GraphL()
    {
        delete[] mark;
        delete[] adj;
    }

    void SetEdge(const int i, const T j, const int weight = 0)
    {
        Edge<T> dist(j, weight);
        adj[i].push_back(dist);
    }
};

#endif