#ifndef MERGE_SORT
#define MERGE_SORT

#include <iostream>
using namespace std;

template <class T>
class MergeSort
{
private:
    T *array;
    int left;
    int middle;
    int right;

public:
    MergeSort(T *arr, int size)
    {
    }
    ~MergeSort()
    {
    }
    void MergeSort(T *arr, int left, int right)
    {
        if (left < right)
        {
            middle = (left + right) / 2;
            MergeSort(arr, size, left, middle);
            MergeSort(arr, size, middle + 1, right);
        }
    }
    void Merge(T *arr, int left, int right)
    {
        for (int i = 0; i < count; i++)
        {
            
        }
    }
};

#endif