#ifndef GRAPH_MAIN
#define GRAPH_MAIN

#include <iostream>
using namespace std;

#include <stack>
#include "GraphM.hpp"

#define unMark -1

class GraphMain
{
private:
    int *pred;
    int nVertice;

private:
    void DFS(GraphM *g, const int &v)
    {
        // previsit()
        // PreVisit(v);
        g->SetMark(v, visited);
        for (int w = g->First(v); w < g->Vertice(); w = g->Next(v, w))
            if (g->GetMark(w) == unvisited)
                DFS(g, w);
        // posVisit()
        // PosVisit(v);
    }

    void BFS(GraphM *g, const int &start)
    {
        queue<int> mqueue;
        mqueue.push(start);
        g->SetMark(start, visited);
        while (!mqueue.empty())
        {
            int v = mqueue.front();
            mqueue.pop();
            // PreVisit(v);
            int w = g->First(v);
            while (w < g->Vertice())
            {
                if (g->GetMark(w) == unvisited)
                {
                    g->SetMark(w, visited);
                    // cout << v << " prev of: " << w << endl;
                    pred[w] = v;
                    mqueue.push(w);
                }
                w = g->Next(v, w);
            }
            // PosVisit(v);
        }
    }
    void TopSortHelper(GraphM *g, const int &v, stack<int> *s)
    {
        g->SetMark(v, visited);
        for (int w = g->First(v); w < g->Vertice(); w = g->Next(v, w))
            if (g->GetMark(w) == unvisited)
                TopSortHelper(g, w, s);
        // cout << v << endl;
        s->push(v);
    }

public:
    GraphMain(int numVertice)
    {
        nVertice = numVertice;
        pred = new int[nVertice];
        ResetPred();
    }
    ~GraphMain()
    {
        delete[] pred;
    }

public:
    void DFSTraverse(GraphM *g)
    {
        g->ResetMark();
        for (int v = 0; v < g->Vertice(); v++)
            if (g->GetMark(v) == unvisited)
                DFS(g, v);
    }

    void BFSTraverse(GraphM *g)
    {
        g->ResetMark();
        for (int v = 0; v < g->Vertice(); v++)
            if (g->GetMark(v) == unvisited)
                BFS(g, v);
    }

    void PreVisit(const int &v)
    {
        cout << "Previsit: " << v << endl;
    }
    void PosVisit(const int &v)
    {
        cout << "Posvisit: " << v << endl;
    }

    void TopoSort(GraphM *g, stack<int> *s)
    {
        g->ResetMark();

        for (int v = 0; v < g->Vertice(); v++)
            if (g->GetMark(v) == unvisited)
                TopSortHelper(g, v, s);
    }

    void PrintPred()
    {
        cout << endl
             << "Pred" << endl;
        cout << "[ ";
        for (int i = 0; i < nVertice; i++)
        {
            cout << pred[i] << " ";
        }
        cout << "]" << endl;
    }
    void ResetPred()
    {
        for (int i = 0; i < nVertice; i++)
        {
            pred[i] = unMark;
        }
    }
};
#endif