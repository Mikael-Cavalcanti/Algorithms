#ifndef MERGE_SORT
#define MERGE_SORT

#include <iostream>
using namespace std;

template <class T>
class MergeSort
{
private:
    T *temp;

private:
    void Merge(T *arr, int left, int right)
    {
        for (int i = left; i <= right; i++)
        {
        }
    }

public:
    void Sort(T arr[], int left, int right)
    {
        if (left < right)
        {
            middle = (left + right) / 2;
            Sort(arr, left, middle);
            sort(arr, middle + 1, right);
            Merge(arr, left, middle);
        }
    }
};

#endif