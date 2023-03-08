#ifndef BST_NODE_TREE
#define BST_NODE_TREE

#include "BinNode.hpp"

template <class Key, class T>
class BSTNode : public BinNode<T>
{
private:
    Key key;
    T value;
    BSTNode *left;
    BSTNode *right;

public:
    BSTNode()
    {
        left = nullptr;
        right = nullptr;
    }
    BSTNode(Key key, T value, BSTNode *l = nullptr, BSTNode *r = nullptr)
    {
        this->key = key;
        this->value = value;
        this->left = l;
        this->right = r;
    }
    ~BSTNode() {}

public:
    void SetKey(const Key &k) { key = k; }
    Key &GetKey() { return key; }

public:
    void SetElement(const T &element) { value = element; }
    T &GetElement() { return value; }
    inline BSTNode *Left() const { return left; }
    inline BSTNode *Right() const { return right; }
    void SetLeft(BinNode<T> *l) { left = (BSTNode *)l; }
    void SetRight(BinNode<T> *r) { right = (BSTNode *)r; }
    bool IsLeaf() { return (left == nullptr && right == nullptr); }
};

#endif