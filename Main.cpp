#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"

int main(int argc, char const *argv[])
{
    int v[3] = {3, 1, 5};
    int n = sizeof(v) / sizeof(v[0]);

    // SelectionSort<int> *selectionSort = new SelectionSort<int>(v, n);
    // selectionSort->Print();
    // selectionSort->Sort();
    // cout << endl;
    // selectionSort->Print();
    // cout << endl;
    //  free(selectionSort);

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

    return 0;
}
