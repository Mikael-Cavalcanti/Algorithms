#ifndef ARRAY_LIST
#define ARRAY_LIST
#include <iostream>
#include "List.hpp"

using namespace std;

#define defaultSize = 1;

template <class T>
class ArrayList : List<T>
{
private:
    int maxSize;
    int listSize;
    int curr;
    T *listArray;

public:
    ArrayList(int size = defaultSize)
    {
        
    }
    ~ArrayList()
    {
    }

public:
    virtual void Clear() {}
    virtual void Insert(const E &item) {}
    virtual void Append(const E &item) {}
    virtual void Remove() {}
    virtual void MoveToStart() {}
    virtual void MoveToEnd() {}
    virtual void Prev() {}
    virtual void Next() {}
    virtual int Length() {}
    virtual int CurrPos() {}
    virtual void MoveToPos(int pos) {}
    virtual const T &GetValue() {}
};
#endif