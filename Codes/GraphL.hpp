#ifndef GRAPH_ADJACENCY_LIST
#define GRAPH_ADJACENCY_LIST

#include "Graph.hpp"
#include "Edge.hpp"
#include <list>

#define visited true
#define unvisited false

using namespace std;

template <class T>
class Graphl : public Graph<T>
{
private:
    list<Edge<T>> *adj;
    int numVertex, numEdge;
    bool *mark;

public:
    Graphl(int numVert) { Init(numVert); }
    ~Graphl()
    {
        delete[] mark;
        delete[] adj;
    }

public:
    void Init(const int n)
    {
        numVertex = n;
        numEdge = 0;

        mark = new bool[GetVertice()];
        for (int i = 0; i < GetVertice(); i++)
            mark[i] = unvisited;

        adj = new list<Edge<T>>[GetVertice()];
    }
    const int GetVertice() const { return numVertex; }
    const int GetEdge() const { return numEdge; }
    const int First(int v) const { return 0; }
    const int Next(int v, int w) const { return 0; }
    void SetEdge(const int i, const int j, int weight)
    {
    }
    void DelEdge(int v1, int v2) {}
    bool IsEdge(int i, int j) { return false; }
    int Weight(int v1, int v2) { return 0; }
    bool GetMark(int v) { return false; }
    void SetMark(int v, bool val) {}
};

#endif