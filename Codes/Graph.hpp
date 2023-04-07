#ifndef GRAPH
#define GRAPH

#include <limits>
using namespace std;

template <typename T>
struct Infinity
{
    static constexpr T value = numeric_limits<T>::max();
};

template <class T>
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
    virtual const int First(int v) const = 0;
    virtual const int Next(int v, int w) const = 0;
    virtual void SetEdge(const int i, const int j, int weight) = 0;
    virtual void DelEdge(int v1, int v2) = 0;
    virtual bool IsEdge(int i, int j) = 0;
    virtual int Weight(int v1, int v2) = 0;
    virtual bool GetMark(int v) = 0;
    virtual void SetMark(int v, bool val) = 0;
};
#endif