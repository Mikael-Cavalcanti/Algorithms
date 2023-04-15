#include <map>
#include <iostream>
#include <limits>
#include "../Codes/GraphL.hpp"
#include "../Codes/GraphM.hpp"
#include "../Codes/BFSTraverse.hpp"

using namespace std;

#define undefined Infinity

struct Data
{
};

class ContestantsRanking
{
private:
    int indexRank;
    map<string, int> *ranking;

public:
    GraphL *graph;

public:
    ContestantsRanking()
    {
        indexRank = 0;
        ranking = new map<string, int>();
    }

    ~ContestantsRanking()
    {
        delete ranking;
    }

public:
    void AddContestant(string name)
    {
        if (ranking->find(name) != ranking->end())
            return;
        ranking->insert(pair<string, int>(name, indexRank));
        indexRank++;
    }

    void PrintRanking()
    {
        for (auto it = ranking->begin(); it != ranking->end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    // string name;
    // ContestantsRanking *ranking;
    // ranking = new ContestantsRanking();

    // for (int i = 0; i < 3; i++)
    // {
    //     cin >> name;
    //     ranking->AddContestant(name);
    // }

    // cout << "Ranking:" << endl;
    // ranking->PrintRanking();

    // delete ranking;
    BFSTraverse *bfs = new BFSTraverse();

    GraphM *graph = new GraphM(6);
    // graph->SetEdge(0, 0);
    graph->SetEdge(0, 2);
    graph->SetEdge(0, 4);
    graph->SetEdge(4, 5);
    graph->SetEdge(2, 1);
    graph->SetEdge(2, 3);
    graph->SetEdge(2, 5);
    graph->SetEdge(1, 5);
    graph->SetEdge(3, 5);

    graph->Print();

    for (int i = 0; i < graph->GetVertices(); i++)
        graph->SetMark(i, unvisited);

    cout << "next: " << graph->Next(2, 5) << endl;

    // bfs->BFS(graph, 0);
    // bfs->PrintDistances();

    delete graph;
    delete bfs;

    return 0;
}
