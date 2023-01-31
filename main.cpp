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

    bool operator<=(const Student &b)
    {
        if (time <= b.time)
            return true;
        else if (name <= b.name && time == b.time)
            return true;
        else if (name == b.name && time == b.time)
            return true;

        return false;
    }

    bool operator>=(const Student &b)
    {
        return (time >= b.time || (name >= b.name && time == b.time) || (name == b.name && time == b.time));
    }
};

//&(significa que essa variável está sendo passando como referência e não como cópia)

int main(int argc, char const *argv[])
{
    Student a, b;
    a.name = "mikael";
    b.name = "ana";
    a.time = 6;
    b.time = 6;

    cout << "eh menor ou igual? " << (a >= b) << endl;

    return 0;
}
