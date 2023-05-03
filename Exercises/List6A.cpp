#include <iostream>
#include <list>
#include <queue>

#define visited true
#define unvisited false
#define noParent -1
#define infinity 60000

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
private:
    void Init(const int n) override
    {
        numVertex = n;
        numEdge = 0;

        mark = new bool[GetVertices()];

        for (int i = 0; i < GetVertices(); i++)
            mark[i] = unvisited;

        adj.resize(GetVertices());
    }

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
    const int GetVertices() const override { return numVertex; }

    const int GetEdges() const override { return numEdge; }

    const int First(const int v) override
    {
        auto it = adj.begin();
        advance(it, v);
        if (it->empty())
            return GetVertices();

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

        // if (IsEdge(i, j))
        // {
        //     cout << "Edge already exists." << endl;
        //     return;
        // }

        it->push_back(e);
        // it->sort([this](const Edge &e1, const Edge &e2)
        //          { return e1.Vertex() <= e2.Vertex(); });

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
        for (auto &edge : *it)
        {
            if (edge.Vertex() == v2)
                return edge.Weight();
        }

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
    Dijkstra(const int n) { Init(n); }
    ~Dijkstra()
    {
        delete[] distance;
        delete[] parent;
    }

public:
    void PathFind(Graph *g, const int start = 0)
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

    int *GetDistance() const { return distance; }

    int *GetParent() const { return parent; }

    const int GetLength(const int v) const { return distance[v]; }

    const int GetParent(const int v) const { return parent[v]; }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases, n, m, S, T;
    GraphL *graph;
    Dijkstra *d;

    cin >> cases;

    for (int i = 1; i <= cases; i++)
    {
        cin >> n >> m >> S >> T;
        graph = new GraphL(n);

        if (m > 0)
        {
            for (int j = 0; j < m; j++)
            {
                int u, v, w;
                cin >> u >> v >> w;
                graph->SetEdge(u, v, w);
                graph->SetEdge(v, u, w);
            }

            d = new Dijkstra(graph->GetVertices());
            d->PathFind(graph, S);
            cout << "Case #" << i << ": " << d->GetLength(T) << endl;
        }
        else
            cout << "Case #" << i << ": unreachable" << endl;
    }

    delete graph;
    delete d;

    return 0;
}
