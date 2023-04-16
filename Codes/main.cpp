
#include <iostream>

using namespace std;

template <class T>
void PrintVector(T v[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << " " << v[i];
    }
    cout << " ]" << endl;
}

struct Student
{
public:
    string name;
    int time;

public:
    bool operator<=(const Student &b)
    {
        if (time <= b.time)
            return true;
        else if (name <= b.name && time == b.time)
            return true;
        else if (name == b.name && time == b.time)
            return true;

        return false;
    }

    bool operator>=(const Student &b)
    {
        return (time >= b.time || (name >= b.name && time == b.time) || (name == b.name && time == b.time));
    }
};

//&(significa que essa variável está sendo passando como referência e não como cópia)

// example to return default value type T
template <class T>
const T &ReturnValue()
{
    static const T value = T();
    return value;
}

#include "BFSTraverse.hpp"
#include "GraphL.hpp"

int main(int argc, char const *argv[])
{
    GraphL *graph = new GraphL(6);

    // edge (0,2)
    graph->SetEdge(0, 2);
    graph->SetEdge(2, 0);
    // edge (0,4)
    graph->SetEdge(0, 4);
    graph->SetEdge(4, 0);
    // edge (2,1)
    graph->SetEdge(2, 1);
    graph->SetEdge(1, 2);
    // edge (2,3)
    graph->SetEdge(2, 3);
    graph->SetEdge(3, 2);
    // edge (2,5)
    graph->SetEdge(2, 5);
    graph->SetEdge(5, 2);
    // edge (1,5)
    graph->SetEdge(1, 5);
    graph->SetEdge(5, 1);
    // edge (3,5)
    graph->SetEdge(3, 5);
    graph->SetEdge(5, 3);
    // edge (4,5)
    graph->SetEdge(4, 5);
    graph->SetEdge(5, 4);

    cout << "---------------------   GRAPH   ---------------------" << endl;
    graph->Print();
    cout << "-----------------------------------------" << endl;

    BFSTraverse *bfs = new BFSTraverse();
    bfs->BFS(graph, 0);
    cout << "---------------------   DISTANCES   ---------------------" << endl;
    // bfs->PrintDistances();
    cout << "-----------------------------------------" << endl;

    // delete bfs;
    delete graph;

    return 0;
}
