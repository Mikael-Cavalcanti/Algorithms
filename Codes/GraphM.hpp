#ifndef GRAPH_ADJACENCY_MATRIX
#define GRAPH_ADJACENCY_MATRIX

#include "Graph.hpp"
#define visited true
#define unvisited false

#include <iostream>
#include <queue>

#define INF(T) (Infinity<T>::value)

template <class T>
class GraphM : public Graph<T>
{
private:
    T **matrix;
    int numVertex, numEdge;
    bool *mark;
    queue<T> *mqueue;

public:
    GraphM() {}
    GraphM(const int numVertex)
    {
        Init(numVertex);
    }
    ~GraphM()
    {
        delete[] mark;
        for (int x = 0; x < numVertex; x++)
            delete[] matrix[x];
        delete[] matrix;
        delete mqueue;
    }

public:
    void Init(const int n)
    {
        numEdge = 0;
        numVertex = n;

        mark = new bool[Vertice()];
        ResetMark();

        matrix = new T *[Vertice()];
        for (int x = 0; x < Vertice(); x++)
            matrix[x] = new T[Vertice()];

        for (int x = 0; x < Vertice(); x++)
            for (int y = 0; y < Vertice(); y++)
                matrix[x][y] = INF(T);
    }
    const int Vertice() const { return numVertex; }
    const int Edge() const { return numEdge; }
    const int First(int v) const
    {
        for (int y = 0; y < Vertice(); y++)
            if (matrix[v][y] != INF(T))
                return y;
        return Vertice();
    }
    const int Next(int v, int w) const
    {
        for (int y = w + 1; y < Vertice(); y++)
            if (matrix[v][y] != INF(T))
                return y;
        return Vertice();
    }
    void SetEdge(const int v1, const int v2, int weight = 1)
    {
        if (weight < 0)
            return;
        if (matrix[v1][v2] == INF(T))
            numEdge++;
        matrix[v1][v2] = weight;
    }
    void DelEdge(int v1, int v2)
    {
        if (matrix[v1][v2] != INF(T))
            numEdge--;
        matrix[v1][v2] = INF(T);
    }
    bool IsEdge(int x, int y) { return matrix[x][y] != INF(T); }
    int Weight(int v1, int v2) { return matrix[v1][v2]; }
    bool GetMark(int v) { return mark[v]; }
    void SetMark(int v, bool val) { mark[v] = val; }

    void PrintGraph()
    {
        for (int x = 0; x < Vertice(); x++)
        {
            for (int y = 0; y < Vertice(); y++)
                cout << matrix[x][y] << " ";
            cout << endl;
        }
    }
    void ResetMark()
    {
        if (mark != nullptr)
            for (int x = 0; x < Vertice(); x++)
                mark[x] = unvisited;
    }
};

#endif