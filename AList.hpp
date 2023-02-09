#ifndef A_LIST
#define A_LIST
#include <iostream>

#include "List.hpp"
#define defaultSize 1

using namespace std;

template <class T>
class AList : List<T>
{
private:
    int maxSize;
    int listSize;
    int curr;
    T *listArray;

public:
    AList(int size = defaultSize)
    {
        maxSize = size;
        listSize = curr = 0;
        listArray = new T[maxSize];
    }
    ~AList() { delete[] listArray; }

    // methods

    void Clear()
    {
        delete[] listArray;
        listSize = curr = 0;
        listArray = new T[maxSize];
    }
    void Insert(const T &item)
    {
        if (listSize > maxSize)
            return;
        for (int i = listSize; i > curr; i--)
            listArray[i] = listArray[i - 1];
        listArray[curr] = item;
        listSize++;
    }
    void Append(const T &item)
    {
        if (listSize >= maxSize)
            return;
        listArray[listSize++] = item;
    }
    void Remove()
    {
        if (curr < 0 || curr >= listSize)
            return;
        T it = listArray[curr];
        for (int i = curr; i < listSize - 1; i++)
        {
            listArray[i] = listArray[i + 1];
        }
        listSize -= 1;
        cout << "item : " << it << "removed" << endl;
    }
    void MoveToStart()
    {
        curr = 0;
    }
    void MoveToEnd()
    {
        curr = listSize;
    }
    void Prev()
    {
        if (curr != 0)
            curr--;
    }
    void Next()
    {
        if (curr < listSize)
            curr++;
    }
    int Length() const { return listSize; }
    int CurrPos() const { return curr; }
    void MoveToPos(int pos)
    {
        if ((pos >= 0) && (pos <= listSize))
        {
            curr = pos;
        }
    }
    const T &GetValue() const
    {
        return listArray[curr];
    }
    bool Find(T value)
    {
        for (MoveToStart(); CurrPos() < Length(); Next())
        {
            if (value == GetValue())
                true;
        }

        return false;
    }
    void Print()
    {
        for (MoveToStart(); CurrPos() < Length(); Next())
        {
            cout << "Item[" << CurrPos() << "] " << GetValue() << " ";
        }
        cout << endl;
    }
};
#endif