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