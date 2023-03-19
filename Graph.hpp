#ifndef GRAPH
#define GRAPH

class Graph
{
private:
    void operator=(const Graph &) {}
    virtual ~Graph() {}

public:
    // return number of vertices
    virtual const int &Vertice() const = 0;
    // return number of edges
    virtual const int &Edge() const = 0;
    virtual const int &First() const = 0;
    virtual const int &Next() const = 0;
    virtual void SetEdge(const int i, const int j, int weight) = 0;
    virtual void DelEdge(int v1, int v2) = 0;
    virtual bool IsEdge(int i, int j) = 0;
    virtual int Weight(int v1, int v2) = 0;
    virtual int GetMark(int v) = 0;
    virtual void SetMark(int v, int val) = 0;
};
#endif