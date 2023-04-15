#ifndef GRAPH_ADJACENCY_MATRIX
#define GRAPH_ADJACENCY_MATRIX

#include "Graph.hpp"
#define visited true
#define unvisited false

#include <iostream>
#include <queue>

#define INF(T) (Infinity<T>::value)

class GraphM : public Graph
{
private:
    int **matrix;
    int numVertex, numEdge;
    bool *mark;
    queue<int> *mqueue;

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

        mark = new bool[GetVertices()];
        ResetMark();

        matrix = new int *[GetVertices()];
        for (int x = 0; x < GetVertices(); x++)
            matrix[x] = new int[GetVertices()];

        for (int x = 0; x < GetVertices(); x++)
            for (int y = 0; y < GetVertices(); y++)
                matrix[x][y] = INF(int);
    }
    const int GetVertices() const override { return numVertex; }
    const int GetEdges() const override { return numEdge; }
    const int First(const int v) override
    {
        for (int y = 0; y < GetVertices(); y++)
            if (matrix[v][y] != INF(int))
                return y;
        return GetVertices();
    }
    const int Next(const int v, const int w) override
    {
        for (int y = w + 1; y < GetVertices(); y++)
            if (matrix[v][y] != INF(int))
                return y;
        return GetVertices();
    }
    void SetEdge(const int v1, const int v2, const int weight = 0) override
    {
        if (weight < 0)
            return;
        if (matrix[v1][v2] == INF(int))
            numEdge++;
        matrix[v1][v2] = weight;
    }
    void DelEdge(const int v1, const int v2) override
    {
        if (matrix[v1][v2] != INF(int))
            numEdge--;
        matrix[v1][v2] = INF(int);
    }
    bool IsEdge(const int x, const int y) override { return matrix[x][y] != INF(int); }
    void SetWeight(const int v1, const int v2, const int weight) override { matrix[v1][v2] = weight; }
    int GetWeight(const int v1, const int v2) override { return matrix[v1][v2]; }
    bool GetMark(const int v) override { return mark[v]; }
    void SetMark(const int v, const bool val) override { mark[v] = val; }

    void Print()
    {
        cout << endl;
        for (int x = 0; x < GetVertices(); x++)
        {
            cout << x << ": ";
            for (int y = 0; y < GetVertices(); y++)
            {
                if (matrix[x][y] != INF(int))
                    cout << y << "(" << matrix[x][y] << ") ";
            }
            cout << endl;
        }
    }
    void ResetMark()
    {
        if (mark != nullptr)
            for (int x = 0; x < GetVertices(); x++)
                mark[x] = unvisited;
    }
};

#endif