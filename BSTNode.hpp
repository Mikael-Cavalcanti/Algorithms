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
    // Key, value, left, right
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
    void SetElement(const T &element) override { value = element; }
    T &GetElement() override { return value; }
    inline BSTNode *GetLeft() const override { return left; }
    inline BSTNode *GetRight() const override { return right; }
    void SetLeft(BinNode<T> *l) override { left = (BSTNode *)l; }
    void SetRight(BinNode<T> *r) override { right = (BSTNode *)r; }
    bool IsLeaf() override { return (left == nullptr && right == nullptr); }
};

#endif