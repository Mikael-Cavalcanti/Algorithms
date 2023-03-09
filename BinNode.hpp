#ifndef BIN_NODE
#define BIN_NODE

template <typename T>
class BinNode
{
public:
    virtual ~BinNode() {} // base destructor
public:
    virtual T &GetElement() = 0;
    virtual void SetElement(const T &) = 0;
    virtual BinNode *GetLeft() const = 0;
    virtual BinNode *GetRight() const = 0;
    virtual void SetLeft(BinNode *) = 0;
    virtual void SetRight(BinNode *) = 0;
    virtual bool IsLeaf() = 0;
};

#endif