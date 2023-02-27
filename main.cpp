
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

int main(int argc, char const *argv[])
{
    int n, *order;
    bool orderEmpty;
    StationManager<int> *manager = nullptr;

    do
    {
        orderEmpty = false;
        cin >> n;

        if (n != 0)
        {
            manager = new StationManager<int>(n);

            do
            {
                order = new int[n];

                for (int i = 0; i < n; i++)
                {
                    cin >> order[i];
                    if (order[i] == 0)
                    {
                        orderEmpty = true;
                        break;
                    }
                }

                if (!orderEmpty)
                {
                    manager->SetOrder(order);
                    manager->Run();
                    manager->Reset();
                }

            } while (!orderEmpty);
        }
        else
        {
            manager->~StationManager();
            manager = nullptr;
        }
        cout << endl;

    } while (n != 0);

    if (n != 0)
        manager->~StationManager();

    return 0;
}
