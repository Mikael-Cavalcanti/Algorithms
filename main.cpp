#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "Swap.hpp"
#include "QuickSort.hpp"

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

int main(int argc, char const *argv[])
{
    int v[3] = {3, 1, 5};
    int n = sizeof(v) / sizeof(v[0]);
    int left = 0, right = n - 1;

    QuickSort<int> *quickSort = new QuickSort<int>();
    PrintVector(v, n);
    quickSort->Sort(v, left, right);
    cout << endl;
    PrintVector(v, n);
    delete quickSort;

    // SelectionSort<int> *selectionSort = new SelectionSort<int>();
    // PrintVector(v, n);
    // selectionSort->Sort(v, n);
    // cout << endl;
    // PrintVector(v, n);
    // cout << endl;
    // selectionSort->~SelectionSort();
    // free(selectionSort);

    // BubbleSort<int> *bubbleSort = new BubbleSort<int>(v, n);
    // bubbleSort->Print();
    // bubbleSort->Sort();
    // cout << endl;
    // bubbleSort->Print();
    // cout << endl;
    // delete (bubbleSort);

    // InsertionSort<int> *insertionSort = new InsertionSort<int>(v, n);
    // insertionSort->Print();
    // insertionSort->Sort();
    // cout << endl;
    // insertionSort->Print();
    // cout << endl;
    // delete (insertionSort);
    //

    return 0;
}
