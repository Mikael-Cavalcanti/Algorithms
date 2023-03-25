#ifndef HASH_DICTIONARY
#define HASH_DICTIONARY

#include "Dictionary.hpp"
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
struct TableCell
{
public:
    bool keyRemoved;
    T *pair;

public:
    TableCell()
    {
        pair = nullptr;
        keyRemoved = false;
    }
    ~TableCell()
    {
        delete pair;
    }
};

template <class Key, class T>
struct KVpair
{
public:
    Key key;
    T value;

public:
    KVpair() {}
    KVpair(Key &key, T &value)
    {
        this->key = key;
        this->value = value;
    }
};

template <class Key, class T>
class HashDic : public Dictionary<Key, T>
{
private:
    int hasTableSize;   // size of the hash table
    int dictionarySize; // number of elements in the dictionary
    TableCell<KVpair<Key, T>> *hashTable;
    int *Perm;

public:
    HashDic()
    {
    }
    ~HashDic()
    {
        Clear();
    }

public:
    void Clear() override {}
    void Insert(const Key &key, const T &value) override
    {
    }
    T Remove(const Key &key) override
    {
        return T();
    }
    T RemoveAny() override
    {
        return T();
    }
    T Find(const Key &key) const override
    {
        return T();
    }
    int Size() override
    {
        return dictionarySize;
    }
};

#endif