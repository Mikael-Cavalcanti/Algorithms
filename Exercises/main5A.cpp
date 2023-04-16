#include <iostream>
#include <map>
#include <list>
#include <queue>

#define infinity 1000000
#define visited true
#define unvisited false

using namespace std;

class BaseEdge
{
protected:
    int vertex;
    int wt;

public:
    BaseEdge() {}
    ~BaseEdge() {}

public:
    void SetVertex(const int v) { vertex = v; }
    const int &Vertex() const { return vertex; }
    void SetWeight(const int w) { wt = w; }
    const int &Weight() const { return wt; }
    virtual bool operator<(const BaseEdge &b)
    {
        return Weight() < b.Weight();
    }
    virtual bool operator>(const BaseEdge &b)
    {
        return Weight() > b.Weight();
    }
    virtual bool operator<=(const BaseEdge &b)
    {
        return Weight() <= b.Weight();
    }
    virtual bool operator>=(const BaseEdge &b)
    {
        return Weight() >= b.Weight();
    }
    virtual bool operator==(const BaseEdge &b)
    {
        return Weight() == b.Weight();
    }
};

class Edge : public BaseEdge
{
public:
    Edge(int v, int w)
    {
        vertex = v;
        wt = w;
    }
};

class Graph
{
private:
    void operator=(const Graph &) {}
    Graph(const Graph &) {}

public:
    Graph() {}
    virtual ~Graph() {}

public:
    virtual void Init(const int n) = 0;
    virtual const int GetVertices() const = 0;
    virtual const int GetEdges() const = 0;
    virtual const int First(const int v) = 0;
    virtual const int Next(const int v, const int w) = 0;
    virtual void SetEdge(const int i, const int j, const int weight) = 0;
    virtual void DelEdge(const int v1, const int v2) = 0;
    virtual bool IsEdge(const int i, const int j) = 0;
    virtual void SetWeight(const int v1, const int v2, const int weight) = 0;
    virtual int GetWeight(const int v1, const int v2) = 0;
    virtual bool GetMark(const int v) = 0;
    virtual void SetMark(const int v, const bool val) = 0;
};

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
            // DelEdge(i, j);
            cout << "Edge already exists." << endl;
            return;
        }

        it->push_back(e);
        it->sort();
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
        auto it2 = it->begin();
        if (IsEdge(v1, v2))
        {
            advance(it2, v2);
            (*it2).SetWeight(weight);
        }
    }

    int GetWeight(const int v1, const int v2) override
    {
        auto it = adj.begin();
        advance(it, v1);
        auto it2 = it->begin();
        if (IsEdge(v1, v2))
            return (*it2).Weight();

        return infinity;
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

struct Member
{
    string name;
    int rank;
    Member() {}
    Member(string name, int rank) : name(name), rank(rank) {}

    bool operator<(const Member &other) const
    {
        if (rank == other.rank)
            return name < other.name;

        return rank < other.rank;
    }
    bool operator<=(const Member &other) const
    {
        if (rank == other.rank)
            return name <= other.name;

        return rank <= other.rank;
    }
    bool operator>(const Member &other) const
    {
        if (rank == other.rank)
            return name > other.name;

        return rank > other.rank;
    }
    bool operator>=(const Member &other) const
    {
        if (rank == other.rank)
            return name >= other.name;

        return rank >= other.rank;
    }
};

class ContestantsRanking
{
private:
    int indexRank;
    map<string, int> *data;
    list<Member> *ranking;
    vector<pair<int, int>> *rankingEdge;
    GraphL *graph;
    BFSTraverse *bfs;

public:
    ContestantsRanking()
    {
        indexRank = 0;
        data = new map<string, int>();
        ranking = new list<Member>();
        rankingEdge = new vector<pair<int, int>>();
    }

    ContestantsRanking(pair<string, int> initialData)
    {
        indexRank = 0;
        data = new map<string, int>();
        ranking = new list<Member>();
        rankingEdge = new vector<pair<int, int>>();

        data->insert(initialData);
        // indexRank++ because add initialData
        indexRank++;
        rankingEdge->push_back({initialData.second, initialData.second});
    }

    ~ContestantsRanking()
    {
        delete data;
        delete ranking;
        delete rankingEdge;
        delete graph;
        delete bfs;
    }

public:
    void AddData(string name)
    {
        if (data->find(name) != data->end())
            return;
        data->insert({name, indexRank});
        indexRank++;
    }

    void AddEdge(vector<string> &names)
    {
        int vertex1, vertex2;
        //(0,1) (0,1)
        vertex1 = data->at(names[0]);
        vertex2 = data->at(names[1]);
        rankingEdge->push_back({vertex1, vertex2});
        vertex1 = data->at(names[1]);
        vertex2 = data->at(names[0]);
        rankingEdge->push_back({vertex1, vertex2});
        //(0,2) (0,2)
        vertex1 = data->at(names[0]);
        vertex2 = data->at(names[2]);
        rankingEdge->push_back({vertex1, vertex2});
        vertex1 = data->at(names[2]);
        vertex2 = data->at(names[0]);
        rankingEdge->push_back({vertex1, vertex2});
        //(1,2) (1,2)
        vertex1 = data->at(names[1]);
        vertex2 = data->at(names[2]);
        rankingEdge->push_back({vertex1, vertex2});
        vertex1 = data->at(names[2]);
        vertex2 = data->at(names[1]);
        rankingEdge->push_back({vertex1, vertex2});
    }

    void CreateGraph()
    {
        graph = new GraphL(data->size());
        for (auto it = rankingEdge->begin(); it != rankingEdge->end(); it++)
        {
            graph->SetEdge(it->first, it->second);
        }
    }

    void CreateRanking()
    {
        bfs = new BFSTraverse();
        for (int i = 0; i < graph->GetVertices(); i++)
            graph->SetMark(i, unvisited);

        bfs->BFS(graph, 0);
    }

    void CreateRankingMap()
    {
        for (auto it = data->begin(); it != data->end(); it++)
        {
            Member member;
            member.name = it->first;
            member.rank = bfs->GetDistance(it->second);
            ranking->push_back(member);
        }
        // sort ranking
        ranking->sort();
    }

    void PrintRankingMap()
    {
        cout << ranking->size() << endl;
        for (auto it = ranking->begin(); it != ranking->end(); it++)
        {
            if (it->rank == infinity)
                cout << it->name << " "
                     << "undefined" << endl;
            else
                cout << it->name << " " << it->rank << endl;
        }
    }

    void PrintData()
    {
        for (auto it = data->begin(); it != data->end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }
    }

    void PrintGraph()
    {
        graph->Print();
    }

    void PrintRanking()
    {
        bfs->PrintDistances();
    }

    void PrintEdge()
    {
        for (auto it = rankingEdge->begin(); it != rankingEdge->end(); it++)
        {
            cout << it->first << " → " << it->second << endl;
        }
    }
};

#define memberAmount 3

int main(int argc, char const *argv[])
{
    int casesAmount, teamsAmount;
    string name;
    ContestantsRanking *ranking;
    vector<string> cacheNames(memberAmount);

    cin >> casesAmount;
    for (int i = 0; i < casesAmount; i++)
    {
        ranking = new ContestantsRanking({"Ahmad", 0});

        cin >> teamsAmount;

        for (int i = 0; i < teamsAmount; i++)
        {
            for (int i = 0; i < memberAmount; i++)
            {
                cin >> name;
                ranking->AddData(name);
                cacheNames[i] = name;
            }

            ranking->AddEdge(cacheNames);
        }

        //
        ranking->CreateGraph();
        ranking->CreateRanking();
        ranking->CreateRankingMap();
        //
        ranking->PrintRankingMap();
    }

    delete ranking;

    return 0;
}
