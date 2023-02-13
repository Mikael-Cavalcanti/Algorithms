
#include "MergeSort.hpp"

#include <iostream>

using namespace std;

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

// example to return default value type T
template <class T>
const T &ReturnValue()
{
    static const T value = T();
    return value;
}

const long long int SumList(long long int list[], int initialIndex, int division, int finalIndex)
{
    long long int sum = 0;

    for (int i = initialIndex; i < finalIndex; i++)
    {
        if (i != division)
            sum += list[i];
    }

    return sum;
}

template <class T>
void CompleteList(T *list, int lenght)
{
    for (int i = 0; i < lenght; i++)
        cin >> list[i];
}

int main(int argc, char const *argv[])
{
    // MergeSort<long long int> *mergeSort;
    // int amountChocolate;
    // long long int *priceList;
    // int amountCupons;
    // int *barCanBuyList;

    // cin >> amountChocolate;

    // priceList = new long long int[amountChocolate];

    // CompleteList<long long int>(priceList, amountChocolate);

    // mergeSort = new MergeSort<long long int>(amountChocolate - 1);
    // mergeSort->Sort(priceList, 0, amountChocolate - 1);

    // PrintVector(priceList, amountChocolate);

    // cin >> amountCupons;

    // barCanBuyList = new int[amountCupons];

    // CompleteList(barCanBuyList, amountCupons);

    // for (int i = 0; i < amountCupons; i++)
    // {
    //     int divisionList = 0;
    //     long long int resultSum = 0;

    //     divisionList = (amountChocolate - barCanBuyList[i]);

    //     resultSum = SumList(priceList, 0, divisionList, amountChocolate);

    //     cout << resultSum << endl;
    // }

    int v[] = {5, 2, 0, 1};

    PrintVector(v, 4);

    MergeSort<int> *sort = new MergeSort<int>(4);
    sort->Sort(v, 0, 3);

    PrintVector(v, 4);

    cout << (int)(7 / 2) << endl;

    return 0;
}
