#ifndef SELECTION_SORT
#define SELECTION_SORT

#include <iostream>
using namespace std;

template <class T>
class SelectionSort
{
private:
    T *array;
    int size;
    T minValue;

private:
    void Swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

public:
    SelectionSort(T arr[], int size)
    {
        this->size = size;
        array = arr;
    }

    ~SelectionSort()
    {
        cout << "Clean Selection" << endl;
    }

    void Sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            minValue = i;
            for (int j = i + 1; j < size; j++)
            {
                if (array[j] < array[minValue])
                {
                    minValue = j;
                    Swap(array[i], array[minValue]);
                }
            }
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