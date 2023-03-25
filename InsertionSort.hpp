#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <iostream>
using namespace std;

template <class T>
class InsertionSort
{
private:
    T *array;
    int size;

public:
    InsertionSort(T arr[], int size)
    {
        this->size = size;
        this->array = arr;
    }

    ~InsertionSort()
    {
        cout << endl
             << "Clean InsertionSort" << endl;
    }

    void Sort()
    {
        T v;
        int j = 0;

        for (int i = 1; i < size; i++)
        {
            v = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > v)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = v;
        }
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