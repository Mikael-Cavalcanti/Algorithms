#ifndef L_STACK
#define L_STACK

using namespace std;
#include "Stack.hpp"
#include "Node.hpp"

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
    void Push(const T &it)
    {
        top = new Node<T>(it, top);
        size++;
    }
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