
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

#include <cmath>
#include "LStack.hpp"
#include "StationManager.hpp"
#include "HasDic.hpp"
#include "BSearchRecursive.hpp"
template <class T>
void Func(int (*hash)(T), T value)
{
    cout << hash() << endl;
}

int Sum(int value)
{
    return value + value;
}

int main(int argc, char const *argv[])
{
    // int n;

    // cout << "Insira o tamanho do Trem: ";
    // cin >> n;

    // StationManager<int> *manager = new StationManager<int>(n);

    // manager->~StationManager();
    int *array = new int[100];

    for (int i = 0; i < 100; i++)
    {
        array[i] = i;
    }

    BSearchRecursive<int> *bSearch = new BSearchRecursive<int>();
    // bSearch->Search(array, 0, 99)

    return 0;
}
