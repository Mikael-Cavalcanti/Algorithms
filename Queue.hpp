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
    //Insert Value in Queue
    virtual void Enqueue(const T &) = 0;
    //Remove Value in Queue
    virtual T Dequeue() = 0;
    virtual const T &FrontValue() const = 0;
    virtual int Length() const = 0;
    virtual bool IsEmpty() const = 0;
};

#endif