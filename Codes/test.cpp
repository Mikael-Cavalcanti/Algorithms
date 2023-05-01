#include <iostream>
#include "GraphL.hpp"
#include "Dijkstra.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    GraphL *g = new GraphL(3);

    // set edge 0-1 and 1-0 100
    g->SetEdge(0, 1, 100);
    g->SetEdge(1, 0, 100);
    cout << g->GetWeight(0, 1) << endl;

    // set edge 0-2 and 2-0 200
    g->SetEdge(0, 2, 200);
    g->SetEdge(2, 0, 200);
    cout << g->GetWeight(0, 2) << endl;

    // set edge 1-2 and 2-1 50
    g->SetEdge(1, 2, 50);
    g->SetEdge(2, 1, 50);
    cout << g->GetWeight(1, 2) << endl;

    cout << "------------Graph------------------" << endl;
    g->Print();
    cout << "-----------------------------------" << endl;

    cout << "--------------Dijsktra----------------" << endl;
    Dijkstra *dijkstra = new Dijkstra(g->GetVertices());
    dijkstra->PathFind(g, 0);
    cout << "Distance from 0 to 2: " << dijkstra->GetLength(2) << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}
