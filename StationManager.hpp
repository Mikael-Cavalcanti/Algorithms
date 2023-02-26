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
    bool hasSolution;

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

        PrintTrain(trainA);
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
        cout << "Add on Station[" << currentIndex << "] = " << trainA[currentIndex] << endl;
        station->Push(trainA[currentIndex]);
        currentIndex++;
    }

    void RemoveOfStation()
    {
        if (station->Length() == 0)
        {
            T value = station->Pop();
            cout << "Add on Train B: [" << currentIndex << "] = " << value << endl;
            trainB[currentIndex] = value;
            PrintTrain(trainB);
        }
    }

    void VerifySolution() const
    {
        if ((station->Length() + sizeTrainB) == sizeTrain)
            hasSolution = false;
    }

    void ShowResult()
    {
        if (hasSolution)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

public:
    StationManager(const int &szTrain)
    {
        this->sizeTrain = szTrain;
        currentIndex = 0;
        hasSolution = true;
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
        cout << endl
             << "finish Program" << endl;
    }

public:
    void Start()
    {
        do
        {
            AddOnStation();
            // bool isOrder = true;
            // while (station->Length() > 0 || isOrder)
            // {
            //     cout << "opa2" << endl;

            //     if (station->TopValue() == order[currentIndex++])
            //     {
            //         RemoveOfStation();
            //     }
            //     else
            //         isOrder = false;
            // }

        } while ((currentIndex < sizeTrain) && (hasSolution));

        ShowResult();
    }

    void Reset()
    {
        for (int i = 0; i < sizeTrain; i++)
        {
            trainB[i] = 0;
        }
        currentIndex = 0;
        hasSolution = true;
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

        // cout << "Order" << endl;
        // PrintTrain(order);
    }
};
#endif