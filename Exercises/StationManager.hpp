#ifndef STATION_MANAGER
#define STATION_MANAGER

#include <iostream>

using namespace std;

#include "LStack.hpp"

template <class T>
class StationManager
{
private:
    int currentIndex, sizeTrain, sizeTrainB;
    T *trainA, *trainB, *order;
    LStack<T> *station;

private:
    void Init()
    {
        trainA = new int[sizeTrain];
        trainB = new int[sizeTrain];

        for (int i = 0; i < sizeTrain; i++)
        {
            trainB[i] = 0;
        }
    }

    void MakeTrain()
    {
        for (int i = 0; i < sizeTrain; i++)
            trainA[i] = (i + 1);
    }

    void PrintTrain(T *train)
    {
        cout << "O";
        for (int j = 0; j < sizeTrain; j++)
            cout << "--[" << train[j] << "]";
        cout << endl;
    }

    void AddOnStation()
    {
        station->Push(trainA[currentIndex]);
    }

    void RemoveOfStation()
    {
        T value = station->Pop();
        sizeTrainB++;
        trainB[currentIndex] = value;
    }

    bool HasSolution()
    {
        bool value = (sizeTrainB == sizeTrain) && station->Length() == 0;
        return value;
    }

    void ShowResult()
    {
        if ((sizeTrainB == sizeTrain) && (station->Length() == 0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

public:
    StationManager(const int &szTrain)
    {
        this->sizeTrain = szTrain;
        currentIndex = 0;
        station = new LStack<T>();
        Init();
        MakeTrain();
    }
    ~StationManager()
    {
        delete trainA;
        delete trainB;
        delete order;
        delete station;
    }

public:
    void Run()
    {
        do
        {
            AddOnStation();
            bool isOrder = true;
            while (station->Length() > 0 && isOrder)
            {
                if (station->TopValue() == trainA[currentIndex])
                {
                    RemoveOfStation();
                    currentIndex++;
                }
                else
                    isOrder = false;
            }

            if (!isOrder)
                currentIndex;

        } while ((currentIndex < sizeTrain) && (!HasSolution()));

        ShowResult();
    }

    void Reset()
    {
        currentIndex = 0;
        station = new LStack<T>();
        trainB = new int[sizeTrain];

        for (int i = 0; i < sizeTrain; i++)
        {
            trainB[i] = 0;
        }
    }

    void SetOrder(T *array)
    {
        order = array;
    }
};
#endif