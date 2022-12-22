#ifndef SELECTION_SORT
#define SELECTION_SORT

#include <iostream>
#include "Swap.hpp"
using namespace std;

template <class T>
class SelectionSort
{
private:
    Swap<T> swap;

public:
    void Sort(T array[], int size)
    {
        int minValue;

        for (int i = 0; i < size - 1; i++)
        {
            minValue = i;
            for (int j = i + 1; j < size; j++)
            {
                if (array[j] < array[minValue])
                {
                    minValue = j;
                    swap.swapBit(array[i], array[minValue]);
                }
            }
        }
    }

    void Print(T array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "[" << i << "]"
                 << " : " << array[i] << endl;
        }
    }
};

#endif