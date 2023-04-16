#ifndef BFS_TRAVERSE
#define BFS_TRAVERSE

#include "Graph.hpp"
#include <queue>
#include <iostream>

using namespace std;

#define unvisited false
#define visited true
#define infinity 1000000

class BFSTraverse
{
private:
    vector<int> distances;

public:
    void BFS(Graph *graph, const int start)
    {
        queue<int> myQueue;
        distances.resize(graph->GetVertices(), infinity);
        myQueue.push(start);
        graph->SetMark(start, visited);
        distances[start] = 0;

        while (!myQueue.empty())
        {
            int v = myQueue.front();
            myQueue.pop();

            // ProcessVertexEarly(v);

            int w = graph->First(v);
            // cout << v << " ";
            // cout << "neighbors: ";

            while (w < graph->GetVertices())
            {

                if (graph->GetMark(w) == unvisited)
                {
                    graph->SetMark(w, visited);
                    myQueue.push(w);
                    distances[w] = distances[v] + 1;
                    // ProcessEdge(v, w);
                    // cout << w << " ";
                }
                w = graph->Next(v, w);
            }

            // cout << endl;

            // ProcessVertexLate(v);
        }
    }

    int GetDistance(const int v) const
    {
        return distances[v];
    }

    void PrintDistances()
    {
        for (int i = 0; i < distances.size(); i++)
        {
            cout << "Distance from 0 to " << i << " is " << distances[i] << endl;
        }
    }
};

#endif