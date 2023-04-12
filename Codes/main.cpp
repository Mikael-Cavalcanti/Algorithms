
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
public:
    string name;
    int time;

public:
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

#include "GraphL.hpp"
#include "GraphM.hpp"
#include <map>

int main(int argc, char const *argv[])
{
    map<string, int> *m = new map<string, int>{
        {"jose", 24},
        {"maria", 25},
        {"mikael", 23},
        {"joao", 26},
    };

    if (m->find("mikael") != m->end())
        cout << "mikael" << endl;
    else
        cout << "not mikel" << endl;

    return 0;
}
