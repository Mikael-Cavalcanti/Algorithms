#include <iostream>
#include <string>

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

#ifndef QUEUE
#define QUEUE

template <class T>
class Queue
{
private:
    void operator=(const Queue &) {}
    Queue(const Queue &) {}

public:
    Queue() {}
    virtual ~Queue() {}

public:
    virtual void Clear() = 0;
    virtual void Enqueue(const T &) = 0;
    virtual T Dequeue() = 0;
    virtual const T &FrontValue() const = 0;
    virtual int Length() const = 0;
    virtual bool IsEmpty() const = 0;
};

#endif

#ifndef L_QUEUE
#define L_QUEUE

#define defaultSize 0

template <class T>
class LQueue : Queue<T>
{
private:
    Node<T> *front;
    Node<T> *rear;
    int size;

public:
    LQueue(int sz = defaultSize)
    {
        front = rear = new Node<T>();
        size = 0;
    }
    ~LQueue()
    {
        Clear();
        delete front;
    }

public:
    void Clear() override
    {
        while (!IsEmpty())
            Dequeue();
    }
    void Enqueue(const T &it) override
    {
        rear->next = new Node<T>(it);
        rear = rear->next;
        size++;
    }
    T Dequeue() override
    {
        if (IsEmpty())
            throw std::out_of_range("A fila está vazia.\n");
        else
        {
            T it = front->next->element;
            Node<T> *temp = front->next;
            front->next = temp->next;

            if (rear == temp)
                rear = front;

            delete temp;
            size--;
            return it;
        }
    }

    const T &FrontValue() const override
    {
        if (IsEmpty())
            throw std::out_of_range("A fila está vazia.\n");
        else
            return front->next->element;
    }

    int Length() const override
    {
        return size;
    }

    bool IsEmpty() const override
    {
        return (size == 0);
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

#define END ']'
#define HOME '['

class ResolveString
{
private:
    int currentIndex;
    string middleText;
    LQueue<string> *end;
    LStack<string> *home;

private:
    void ControllerButtons(string &text)
    {
        while (currentIndex < text.length())
        {
            if (text[currentIndex] == HOME)
            {
                currentIndex++;
                ButtonHome(text);
            }
            else if (text[currentIndex] == END)
            {
                currentIndex++;
                ButtonEnd(text);
            }
        }
    }
    void ButtonHome(string &text)
    {
        //  cout << "Apertei Home" << endl;
        string aux;

        for (; currentIndex < text.length(); currentIndex++)
        {
            if (text[currentIndex] == HOME || text[currentIndex] == END)
                break;
            else
                aux += text[currentIndex];
        }

        home->Push(aux);
    }

    void ButtonEnd(string &text)
    {
        // cout << "Apertei End" << endl;
        string aux;

        for (; currentIndex < text.length(); currentIndex++)
        {
            if (text[currentIndex] == HOME || text[currentIndex] == END)
                break;
            else
                aux += text[currentIndex];
        }
        end->Enqueue(aux);
    }

    void SetMiddleText(string &text)
    {
        for (currentIndex = 0; currentIndex < text.length() - 1; currentIndex++)
        {
            if (text[currentIndex] == HOME || text[currentIndex] == END)
            {
                middleText = text.substr(0, currentIndex);
                break;
            }
        }
        // cout << "index [" << currentIndex << "]: " << text[currentIndex] << endl;
    }

    void ShowResolution()
    {
        while (home->Length() != 0)
        {
            cout << home->Pop();
        }

        cout << middleText;

        while (end->Length() != 0)
        {
            cout << end->Dequeue();
        }

        cout << endl;
    }

public:
    ResolveString()
    {
        end = new LQueue<string>();
        home = new LStack<string>();
        currentIndex = 0;
    }
    ~ResolveString()
    {
        delete end;
        delete home;
    }

public:
    void RunResolution(string &text)
    {
        // core function
        SetMiddleText(text);
        ControllerButtons(text);

        // show result
        ShowResolution();
    }
};

int main(int argc, char const *argv[])
{
    string text;
    ResolveString *resolve = new ResolveString();

    while (getline(cin, text))
    {
        resolve->RunResolution(text);

        resolve = new ResolveString();
    }

    delete resolve;

    return 0;
}