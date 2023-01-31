#ifndef LIST
#define LIST

template <class T>

class List
{
    // methods
public:
    List() {}
    virtual ~List() {}

public:
    virtual void Clear();
    virtual void Insert(const E &item) = 0;
    void Append(const E &item) = 0;
    T Remove() = 0;
};

#endif