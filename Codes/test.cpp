#include <iostream>
#include "GraphL.hpp"
#include "TopoSort.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    TopoSort *ts;
    GraphL *g = new GraphL(7);
    // set edge (0, 1) with weight 1
    g->SetEdge(0, 1, 1);
    // set edge (0, 2) with weight 1
    g->SetEdge(0, 2, 1);
    // set edge (1, 5) with weight 1
    g->SetEdge(1, 5, 1);
    // set edge (1, 3) with weight 1
    g->SetEdge(1, 3, 1);
    // set edge (1, 4) with weight 1
    g->SetEdge(1, 4, 1);
    // set edge (2, 3) with weight 1
    g->SetEdge(2, 3, 1);
    // set edge (3, 4) with weight 1
    g->SetEdge(3, 4, 1);
    // set edge (4, 6) with weight 1
    g->SetEdge(4, 6, 1);

    // print graph
    g->Print();

    ts = new TopoSort(g);

    ts->Print();

    delete g;
    delete ts;

    return 0;
}
