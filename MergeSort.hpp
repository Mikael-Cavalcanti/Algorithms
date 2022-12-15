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
        int middle = 0;

        for (int i = left; i <= right; i++)
            temp[i] = arr[i];

        middle
    }
    void Swap(T &a, T &b)
    {
        T temp;
        temp = a;
        a = b;
        b = temp;
    }

public:
    void Sort(T arr[], int left, int right)
    {
        int middle = 0;
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