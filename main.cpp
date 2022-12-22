#include "SelectionSort.hpp"
#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "Swap.hpp"
#include "QuickSort.hpp"
#include "BSearchRecursive.hpp"
#include "BSearch.hpp"

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

int main(int argc, char const *argv[])
{
    // string exist = "test";
    // int v[] = {3, 1, 5};
    // int n = sizeof(v) / sizeof(v[0]);
    // int left = 0, right = n - 1;
    // string v = "cba";
    // int left = 0, right = v.size() - 1;

    // cout << "Size: " << v.size() << endl;

    // char test[v.size()];

    // for (int i = 0; i < v.size(); i++)
    // {
    //     test[i] = v[i];
    // }

    // QuickSort<char> *quickSort = new QuickSort<char>();
    // PrintVector<char>(test, v.size());
    // quickSort->Sort(test, 0, right);
    // cout << endl;

    // PrintVector<char>(test, v.size());

    // cout << " V : " << v << endl;

#pragma BSearchRecursive
    // BSearchRecursive<int> *bsearch = new BSearchRecursive<int>();
    // cout << endl;
    // bool res = bsearch->Search(v, left, right, 3);
    // cout << "Result : " << res << endl;
    // cout << endl;
#pragma endregion

    // BSearch<int> *bsearch = new BSearch<int>();
    // cout << endl;
    // int item = 10;
    // bool res = bsearch->Find(v, left, right, item);
    // exist = res == true ? "exist" : "don't exist";
    // cout << "The Item: [" << item << "] " << exist << " in Array" << endl;
    // cout << endl;

    // delete bsearch;
    // delete quickSort;

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
    return 0;
}
