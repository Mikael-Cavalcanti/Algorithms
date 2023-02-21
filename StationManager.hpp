#ifndef STATION_MANAGER
#define STATION_MANAGER

#include <iostream>

using namespace std;

#include "LStack.hpp"
#include "LList.hpp"

template <class T>
class StationManager
{
private:
    int currentIndex, sizeTrain;
    LList<T> *trainA, *trainB;
    Stack<T> *station;

private:
    void MakeTrain()
    {
        for (int i = 1; i <= sizeTrain; i++)
            trainA->Append(i);
        trainA->Print();
    }

public:
    StationManager(const int &szTrain)
    {
        this->sizeTrain = szTrain;
        Init();
        MakeTrain();
    }
    ~StationManager()
    {
        delete trainA;
        delete trainB;
        delete station;
        cout << endl
             << "finish Program" << endl;
    }

    void Init()
    {
        trainA = new LList<T>();
        trainB = new LList<T>();
    }
};

#endif