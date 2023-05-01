#ifndef ADJACENCY_GRAPH
#define ADJACENCY_GRAPH

#include "Graph.hpp"
#include "Edge.hpp"
#include <list>
#include <iterator>

#define visited true
#define unvisited false

using namespace std;

class GraphL : public Graph
{
public:
    int numVertex, numEdge;
    bool *mark;
    list<list<Edge>> adj;

public:
    GraphL(const int nVertex)
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

        mark = new bool[GetVertices()];

        for (int i = 0; i < GetVertices(); i++)
            mark[i] = unvisited;

        adj.resize(GetVertices());
    }

    const int GetVertices() const override { return numVertex; }

    const int GetEdges() const override { return numEdge; }

    const int First(const int v) override
    {
        auto it = adj.begin();
        advance(it, v);
        if (it->empty())
            return GetVertices();
        else
            return (*it->begin()).Vertex();
    }

    const int Next(const int v, const int w) override
    {
        if (IsEdge(v, w))
        {
            auto it = adj.begin();
            advance(it, v);
            for (auto it2 = it->begin(); it2 != it->end(); it2++)
            {
                if ((*it2).Vertex() == w)
                {
                    it2++;
                    if (it2 != it->end())
                        return (*it2).Vertex();
                    else
                        return GetVertices();
                }
            }
        }
        return GetVertices();
    }

    void SetEdge(const int i, const int j, const int weight = 0) override
    {
        if (GetWeight(i, j) <= 0)
            return;
        Edge e(j, weight);
        auto it = adj.begin();
        advance(it, i);

        if (IsEdge(i, j))
        {
            cout << "Edge already exists." << endl;
            return;
        }

        it->push_back(e);
        it->sort([this](const Edge &e1, const Edge &e2)
                 { return e1.Vertex() <= e2.Vertex(); });

        numEdge++;
    }

    void DelEdge(const int v1, const int v2) override
    {
        auto it = adj.begin();
        advance(it, v1);
        auto it2 = it->begin();
        if (IsEdge(v1, v2))
        {
            advance(it2, v2);
            it->erase(it2);
            numEdge--;
        }
    }

    bool IsEdge(const int i, const int j) override
    {
        auto it = adj.begin();
        advance(it, i);
        for (auto &edge : *it)
        {
            if (edge.Vertex() == j)
                return true;
        }
        return false;
    }

    void SetWeight(const int v1, const int v2, const int weight = 0) override
    {
        auto it = adj.begin();
        advance(it, v1);
        if (IsEdge(v1, v2))
        {
            for (auto &edge : *it)
            {
                if (edge.Vertex() == v2)
                    edge.SetWeight(weight);
            }
        }
    }

    int GetWeight(const int v1, const int v2) override
    {
        auto it = adj.begin();
        advance(it, v1);
        auto it2 = it->begin();
        if (IsEdge(v1, v2))
        {
            for (auto &edge : *it)
            {
                if (edge.Vertex() == v2)
                    return edge.Weight();
            }
        }

        return Infinity<int>::value;
    }

    bool GetMark(const int v) override { return mark[v]; }

    void SetMark(const int v, const bool val) override { mark[v] = val; }

    void Print()
    {
        for (int i = 0; i < GetVertices(); i++)
        {
            cout << i << ": ";
            auto it = adj.begin();
            advance(it, i);
            for (auto &edge : *it)
            {
                cout << edge.Vertex() << " ";
            }
            cout << endl;
        }
    }

    void PrintWeight()
    {
        cout << endl;
        for (int i = 0; i < GetVertices(); i++)
        {
            cout << i << ": ";
            auto it = adj.begin();
            advance(it, i);
            for (auto &edge : *it)
            {
                cout << edge.Vertex() << "(" << edge.Weight() << ") ";
            }
            cout << endl;
        }
    }
};

#endif