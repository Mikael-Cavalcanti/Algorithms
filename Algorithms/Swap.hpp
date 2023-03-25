#ifndef SWAP
#define SWAP

template <class T>
class Swap
{
public:
    Swap()
    {
    }

    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
};

#endif