#ifndef GRAPH
#define GRAPH

#include <limits>
using namespace std;

template <typename T>
struct Infinity
{
    static constexpr T value = numeric_limits<T>::max();
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
    virtual int GetWeight(const int v1, const int v2) = 0;
    virtual bool GetMark(const int v) = 0;
    virtual void SetMark(const int v, const bool val) = 0;
};
#endif