#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "Swap.hpp"
#include "QuickSort.hpp"
#include "BSearchRecursive.hpp"
#include "BSearch.hpp"
#include "MergeSort.hpp"

#include <string>

template <class T>
void PrintVector(T v[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << " " << v[i];
    }
    cout << " ]" << endl;
}

struct Student
{
    string name;
    int time;

    bool operator<(const Student &b)
    {
        if (name < b.name)
            return true;

        return false;
    }

    int operator+(const Student &b)
    {
        return time + b.time;
    }
};

int main(int argc, char const *argv[])
{
    Student a, b;
    a.time = 5;
    b.time = 2;
    cout << "soma: " << (a + b) << endl;

    return 0;
}
