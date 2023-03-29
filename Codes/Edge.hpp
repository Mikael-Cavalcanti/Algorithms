#ifndef EDGE_ADJACENCY_LIST_GRAPH
#define EDGE_ADJACENCY_LIST_GRAPH

template <typename T>
class Edge
{
private:
    T vert;
    int wt;

public:
    Edge()
    {
        vert = T();
        wt = 0;
    }
    Edge(const T v, const int w)
    {
        vert = v;
        wt = w;
    }
    const T Vertex() const { return vert; }
    const int Weight() const { return wt; }
};

#endif