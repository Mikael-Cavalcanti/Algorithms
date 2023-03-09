#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include "Dictionary.hpp"
#include "BSTNode.hpp"

template <class Key, class T>
class BSTDictionary : public Dictionary<Key, T>
{
private:
    BSTNode<Key, T> *root;
    int nodeCount;

private:
    bool DictionaryIsEmpty()
    {
        return root == nullptr;
    }

    void ClearHelp(BSTNode<Key, T> *root)
    {
        if (root == nullptr)
            return;
        ClearHelp(root->GetLeft());
        ClearHelp(root->GetRight());
        delete root;
    }

    BSTNode<Key, T> *InsertHelp(BSTNode<Key, T> *rt, const Key &key, const T &element)
    {
        if (rt == nullptr)
            return new BSTNode<Key, T>(key, element);

        if (rt->GetKey() > key)
            rt->SetLeft(InsertHelp(rt->GetLeft(), key, element));
        else
            rt->SetRight(InsertHelp(rt->GetRight(), key, element));
        return rt;
    }

    BSTNode<Key, T> *DeleteMin(BSTNode<Key, T> *rt)
    {
        if (rt->GetLeft() == nullptr)
            return rt->GetRight();
        rt->SetLeft(DeleteMin(rt->GetLeft()));
        return rt;
    }

    BSTNode<Key, T> *GetMin(BSTNode<Key, T> *rt)
    {
        if (rt->GetLeft() == nullptr)
            return rt;

        return GetMin(rt->GetLeft());
    }

    BSTNode<Key, T> *RemoveHelp(BSTNode<Key, T> *rt, const Key &key)
    {
        if (rt == nullptr)
            return nullptr;

        if (rt->GetKey() > key)
            rt->SetLeft(RemoveHelp(rt->GetLeft(), key));
        else if (rt->GetKey() < key)
            rt->SetRight(RemoveHelp(rt->GetRight(), key));
        else
        {
            if (rt->GetLeft() == nullptr)
                return rt->GetRight();
            else if (rt->GetRight() == nullptr)
                return rt->GetLeft();
            else
            {
                BSTNode<Key, T> *temp = GetMin(rt->GetRight());
                rt->SetElement(temp->GetElement());
                rt->SetKey(temp->GetKey());
                rt->SetRight(DeleteMin(rt->GetRight()));
            }
        }

        return rt;
    }

    T FindHelp(BSTNode<Key, T> *rt, const Key &key) const
    {
        if (rt == nullptr)
            throw std::invalid_argument("Tree Empty");

        if (rt->GetKey() > key)
            return FindHelp(rt->GetLeft(), key);
        else if (rt->GetKey() == key)
            return rt->GetElement();
        else
            return FindHelp(rt->GetRight(), key);
    }

public:
    BSTDictionary()
    {
        root = nullptr;
        nodeCount = 0;
    }
    ~BSTDictionary() { ClearHelp(root); }

public:
    void Clear() override
    {
        ClearHelp(root);
        root = nullptr;
        nodeCount = 0;
    }

    void Insert(const Key &key, const T &value) override
    {
        root = InsertHelp(root, key, value);
        nodeCount++;
    }

    T Remove(const Key &key) override
    {
        T temp = FindHelp(root, key);

        root = RemoveHelp(root, key);
        nodeCount--;

        return temp;
    }

    T Find(const Key &key) const override
    {
        return FindHelp(root, key);
    }

    int Size() override { return nodeCount; }
};

#endif