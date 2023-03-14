#ifndef GRAPH
#define GRAPH

template <class T>
class Graph
{
public:
    virtual const T &Node() const = 0;
    virtual const T &Edge() const = 0;
    virtual const T &First() const = 0;
    virtual const T &Next() const = 0;
    virtual void SetEdge(const int i, const int j, T weight) = 0;
};
#endif