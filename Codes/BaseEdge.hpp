#ifndef BASE_EDGE
#define BASE_EDGE

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

#endif