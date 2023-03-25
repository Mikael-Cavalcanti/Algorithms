#ifndef QUICK_SORT
#define QUICK_SORT

#include "Swap.hpp"

template <class T>
class QuickSort
{
private:
    Swap<T> swap;

    int HoarePartition(T array[], int left, int right)
    {
        T pivot = array[left];
        int i = left, j = right + 1;

        do
        {
            do
                i++;
            while (!(array[i] >= pivot || i >= right));

            do
                j--;
            while (!(array[j] <= pivot));
            swap.swap(array[i], array[j]);
        } while (!(i >= j));
        swap.swap(array[i], array[j]);
        swap.swap(array[left], array[j]);
        return j;
    }

public:
    QuickSort()
    {
    }
    ~QuickSort()
    {
    }

    // left is index 0 and right is (length -1)
    void Sort(T array[], int left, int right)
    {

        if (left < right)
        {
            int splitPosition = 0;
            splitPosition = HoarePartition(array, left, right);
            Sort(array, left, splitPosition - 1);
            Sort(array, splitPosition + 1, right);
        }
    }
};

#endif