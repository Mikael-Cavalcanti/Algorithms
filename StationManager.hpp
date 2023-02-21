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
    void Init()
    {
        trainA = new LList<T>();
        trainB = new LList<T>();
    }

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

public:
    /*
    - array trem - stack station - array new trem

    1 - pego o vagão;
    - coloco na station;
    - verifico se está na ordem;
    - se estiver coloco no novo trem até terminar os trens da estaçao;
    - caso a station não esteja vazia;
    - caso a soma do tamanho da station + B = n, não tem solução;
    2 - volto para o passo até que a station esteja vazia ou não tenha solução;

    add in station
    remove in station
    verify order
    */
};

#endif