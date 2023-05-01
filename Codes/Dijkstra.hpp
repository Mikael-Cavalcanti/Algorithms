#ifndef DIJKSTRA
#define DIJKSTRA

#include <queue>
#include "Graph.hpp"

#define infinity 9999999
#define noParent -1
#define visited true
#define unvisited false

using namespace std;

struct Data
{
    int u, v, distance;

    Data() {}

    Data(const int u, const int v, const int distance) : u(u), v(v), distance(distance) {}

    bool operator<(const Data &d) const
    {
        return this->distance < d.distance;
    }

    bool operator>(const Data &d) const
    {
        return this->distance > d.distance;
    }

    bool operator==(const Data &d) const
    {
        return this->distance == d.distance;
    }

    bool operator!=(const Data &d) const
    {
        return this->distance != d.distance;
    }

    bool operator<=(const Data &d) const
    {
        return this->distance <= d.distance;
    }

    bool operator>=(const Data &d) const
    {
        return this->distance >= d.distance;
    }
};

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
    void PathFind(Graph *g, const int start, int *d)
    {
        for (int i = 0; i < g->GetVertices(); i++)
        {
            distance[i] = infinity;
            parent[i] = noParent;
            g->SetMark(i, unvisited);
        }

        priority_queue<Data, vector<Data>, greater<Data>> minHeap;

        distance[start] = 0;
        minHeap.push(Data(start, start, 0));

        for (int i = 0; i < g->GetVertices(); i++)
        {
            int p, v, w;

            do
            {
                if (minHeap.empty())
                    return;

                p = minHeap.top().u;
                v = minHeap.top().v;

                minHeap.pop();
            } while (g->GetMark(v) == visited);

            g->SetMark(v, visited);
            parent[v] = p;
            w = g->First(v);

            while (w < g->GetVertices())
            {
                if (g->GetMark(w) == unvisited && (distance[w] > distance[v] + g->GetWeight(v, w)))
                {
                    distance[w] = distance[v] + g->GetWeight(v, w);
                    minHeap.push(Data(v, w, distance[w]));
                }
                w = g->Next(v, w);
            }
        }
    }
};

#endif