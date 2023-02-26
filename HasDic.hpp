#ifndef HASH_DICTIONARY
#define HASH_DICTIONARY

#include "Dictionary.hpp"
#include <cmath>
#include <iostream>

using namespace std;

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
class HasDic
{
private:
    int m; // size of the hash table
    int n; // number of elements in the dictionary
    KVpair<Key, T> *H;
    int *Perm;

private:
    void Swap(KVpair<Key, T> &a, KVpair<Key, T> b)
    {
        KVpair<Key, T> temp;
        temp = a;
        a = b;
        b = temp;
    }

public:
    HasDic(T value)
    {
        if (sizeof(T) == sizeof(string))
            cout << "string" << endl;

        if (sizeof(T) == sizeof(int))
            cout << "int" << endl;
    }
};

#endif