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
            temp[i] = arr[i];

        int middle, i1, i2;

        middle = (left + right) / 2;
        i1 = left;
        i2 = middle + 1;

        for (int curr = left; curr <= right; curr++)
        {
            if (i1 == middle + 1)
                arr[curr] = temp[i2++];
            else if (i2 > right)
                arr[curr] = temp[i1++];
            else if (temp[i1] <= temp[i2])
                arr[curr] = temp[i1++];
            else
                arr[curr] = temp[i2++];
        }
    }

public:
    MergeSort(int right)
    {
        temp = new T[right + 1];
    }
    ~MergeSort()
    {
        delete temp;
    }

    void Sort(T *arr, int left, int right)
    {
        if (left < right)
        {
            int middle;

            middle = (left + right) / 2;
            Sort(arr, left, middle);
            Sort(arr, middle + 1, right);
            Merge(arr, left, right);
        }
    }
};

#endif