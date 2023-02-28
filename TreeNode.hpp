#ifndef TREE_NODE_BASE
#define TREE_NODE_BASE

template <class Key, class T>
class TreeNode
{
protected:
    Key key;
    T element;
    TreeNode<Key, T> *left;
    TreeNode<key, T> *right;

public:
    virtual ~TreeNode() {}

public:
    virtual T &Element() = 0;
    virtual void SetElement(const T &) = 0;
    virtual BinNode *Left() const = 0;
    virtual void SetLeft(BinNode *) = 0;
    virtual BinNode *Right() const = 0;
    virtual void SetRight(BinNode *) = 0;
    virtual bool isLeaf() = 0;
};

// template <class key, class T>
// T &TreeNode<key, T>::Element()
// {
//     return T();
// }

#endif