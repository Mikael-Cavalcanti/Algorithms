#ifndef L_QUEUE
#define L_QUEUE

#include "Queue.hpp"
#include "Node.hpp"

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