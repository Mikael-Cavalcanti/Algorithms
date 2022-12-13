#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include <iostream>
using namespace std;

template <class T>
class BubbleSort
{
private:
    T *array;
    int size;

private:
    void Swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

public:
    BubbleSort(T arr[], int size)
    {
        this->size = size;
        array = arr;
    }

    ~BubbleSort()
    {
        cout << "Clean Bubble" << endl;
    }

    void Sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (array[j + 1] < array[j])
                {
                    Swap(array[j], array[j + 1]);
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