#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <iostream>
using namespace std;

template <class T>
class InsertionSort
{
private:
    T *array;

public:
    InsertionSort(T arr[])
    {
        this->array = arr;//
    }
    ~InsertionSort()
    {
        cout << endl
             << "Clean InsertionSort" << endl;
    }
    void Sort()
    {
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "[" << i << "]"
                 << " : " << array[i] << endl;
        }
    }
};

#endif