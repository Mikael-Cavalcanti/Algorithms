#ifndef FLOYD_WARSHALL
#define FLOYD_WARSHALL

#include <iostream>
#include "Graph.hpp"

using namespace std;

class FloydWarshall
{
private:
    int **D;
    int n;

public:
    FloydWarshall(const int n) { Init(n); }
    ~FloydWarshall()
    {
        for (int y = 0; y < n; y++)
            delete[] D[y];
        delete[] D;
    }

public:
    void Init(const int n)
    {
        this->n = n;
        D = new int *[n];
        for (int y = 0; y < n; y++)
            D[y] = new int[n];
    }

    void Floyd(Graph *g)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    D[i][j] = 0;
                else
                    D[i][j] = g->GetWeight(i, j);
            }
        }

        // print D
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
                cout << D[y][x] << " ";
            cout << endl;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (D[i][k] != Infinity<int>::value && D[k][j] != Infinity<int>::value && D[i][k] + D[k][j])
                        D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    const int PathDistance(const int u, const int v) const
    {
        return D[u][v];
    }
};

#endif