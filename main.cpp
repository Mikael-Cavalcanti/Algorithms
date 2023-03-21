
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

#include <cmath>
#include <stack>
#include "GraphM.hpp"
#include "GraphMain.hpp"

int main(int argc, char const *argv[])
{
    stack<int> *s = new stack<int>();

    GraphMain *main = new GraphMain();

    GraphM *graph = new GraphM(7);
    // graph->SetEdge(0, 2);
    // graph->SetEdge(2, 0);
    // graph->SetEdge(0, 4);
    // graph->SetEdge(4, 0);
    // graph->SetEdge(4, 5);
    // graph->SetEdge(5, 4);
    // graph->SetEdge(2, 1);
    // graph->SetEdge(1, 2);
    // graph->SetEdge(2, 3);
    // graph->SetEdge(3, 2);
    // graph->SetEdge(3, 5);
    // graph->SetEdge(5, 3);
    // graph->SetEdge(1, 5);
    // graph->SetEdge(5, 1);
    // graph->SetEdge(2, 5);
    // graph->SetEdge(5, 2);

    // graph->PrintGraph();

    // main->DFSTraverse(graph);
    // main->BFSTraverse(graph);

    graph->SetEdge(0, 1);
    graph->SetEdge(0, 2);
    graph->SetEdge(1, 5);
    graph->SetEdge(1, 4);
    graph->SetEdge(1, 3);
    graph->SetEdge(4, 6);
    graph->SetEdge(2, 3);
    graph->SetEdge(3, 4);

    graph->PrintGraph();

    cout << endl
         << "TopoSort" << endl;
    main->TopoSort(graph, s);

    while (!s->empty())
    {
        cout << s->top() + 1 << endl;
        s->pop();
    }

    delete graph;
    delete main;
    delete s;

    return 0;
}
