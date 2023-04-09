#ifndef EDGE_ADJACENCY_LIST_GRAPH
#define EDGE_ADJACENCY_LIST_GRAPH

class Edge
{
private:
    int vertex;
    int wt;

public:
    Edge() { vertex = wt = 0; }
    Edge(const int v, const int w)
    {
        vertex = v;
        wt = w;
    }
    const int &Vertex() const { return vertex; }
    const int &Weight() const { return wt; }

    bool operator<(const Edge &b)
    {
        return wt < b.wt;
    }
    bool operator>(const Edge &b)
    {
        return wt > b.wt;
    }
    bool operator<=(const Edge &b)
    {
        return wt <= b.wt;
    }
    bool operator>=(const Edge &b)
    {
        return wt >= b.wt;
    }
    bool operator==(const Edge &b)
    {
        return wt == b.wt;
    }
};

#endif