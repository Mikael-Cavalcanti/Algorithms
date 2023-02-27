#include <iostream>

using namespace std;

#ifndef NODE
#define NODE

template <class T>
class Node
{
public:
    T element;
    Node *next;

public:
    Node(Node *nextVal = NULL)
    {
        next = nextVal;
    }
    Node(const T &elemVal, Node *nextVal = NULL)
    {
        element = elemVal;
        next = nextVal;
    }
};
#endif

#ifndef STACK
#define STACK

template <class T>
class Stack
{
private:
    void operator=(const Stack &) {}
    Stack(const Stack &) {}

public:
    Stack() {}
    virtual ~Stack() {}

public:
    virtual void Clear() = 0;
    virtual void Push(const T &it) = 0;
    virtual T Pop() = 0;
    virtual const T &TopValue() const = 0;
    virtual int Length() const = 0;
    virtual bool IsEmpty() const = 0;
};

#endif

#ifndef L_STACK
#define L_STACK
#define defaultSize 0

template <class T>
class LStack : Stack<T>
{
private:
    Node<T> *top;
    int size;

public:
    LStack() : top(nullptr), size(defaultSize) {}
    ~LStack() { Clear(); }

public:
    void Clear()
    {
        while (!IsEmpty())
            Pop();
    }
    // Insert Item on stack
    void Push(const T &it)
    {
        top = new Node<T>(it, top);
        size++;
    }
    // Remove Item of stack
    T Pop()
    {
        if (top == nullptr)
            throw runtime_error("Stack is empty");

        T it = top->element;
        Node<T> *temp = top;
        top = top->next;
        delete temp;
        size--;
        return it;
    }
    const T &TopValue() const
    {
        if (top == nullptr)
            throw runtime_error("Stack is empty");

        return top->element;
    }
    int Length() const { return size; }
    bool IsEmpty() const { return top == nullptr; }
};
#endif

#ifndef STATION_MANAGER
#define STATION_MANAGER

template <class T>
class StationManager
{
private:
    int currentIndex, sizeTrain;
    T *trainA, *trainB, *order;
    LStack<T> *station;

private:
    void Init()
    {
        trainA = new T[sizeTrain];
        trainB = new T[sizeTrain];
        order = new T[sizeTrain];

        for (int i = 0; i < sizeTrain; i++)
        {
            trainB[i] = 0;
        }
        currentIndex = 0;
        station = new LStack<T>();
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

    bool HasSolution()
    {
        int indexB = 0;
        while (indexB < sizeTrain)
        {
            if (station->Length() != 0 && order[indexB] == station->TopValue())
            {
                // add in trainB
                trainB[indexB] = station->Pop();
                indexB++;
            }
            else if (currentIndex < sizeTrain)
            {
                // add in station
                station->Push(trainA[currentIndex]);
                currentIndex++;
            }
            else
            {
                return false;
            }
        }

        return true;
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
        delete[] trainA;
        delete[] trainB;
        delete[] order;
        delete station;
    }

public:
    void Run()
    {
        string res = HasSolution() ? "Yes" : "No";
        cout << res << endl;
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
        for (int o = 0; o < sizeTrain; o++)
            order[o] = array[o];
    }
};
#endif

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

            if (orderEmpty)
                cout << endl;
        }
        else
        {
            manager->~StationManager();
            manager = nullptr;
        }

    } while (n != 0);

    if (n != 0)
        manager->~StationManager();

    return 0;
}