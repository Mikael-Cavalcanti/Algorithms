#ifndef BIN_NODE
#define BIN_NODE

// Binary tree node
template <class T>
class BinNode
{
public:
    virtual ~BinNode() {}

public:
    virtual T &Element() = 0;
    virtual void SetElement(const T &) = 0;
    virtual BinNode *Left() const = 0;
    virtual void SetLeft(BinNode *) = 0;
    virtual BinNode *Right() const = 0;
    virtual void SetRight(BinNode *) = 0;
    virtual bool isLeaf() = 0;
};

template <class T>
T &BinNode<T>::Element()
{
    return T();
}

#endif