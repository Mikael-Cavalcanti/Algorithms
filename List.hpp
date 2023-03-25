#ifndef LIST
#define LIST

template <class T>
class List
{
private:
    void operator=(const List &) {}
    List(const List &) {}

public:
    List() {}
    virtual ~List() {}
    // methods
public:
    virtual void Clear() = 0;
    virtual void Insert(const T &item) = 0;
    virtual void Append(const T &item) = 0;
    virtual void Remove() = 0;
    virtual void MoveToStart() = 0;
    virtual void MoveToEnd() = 0;
    virtual void Prev() = 0;
    virtual void Next() = 0;
    virtual int Length() const = 0;
    virtual int CurrPos() const = 0;
    virtual void MoveToPos(int pos) = 0;
    virtual const T &GetValue() const = 0;
    virtual bool Find(T value) = 0;
};

#endif