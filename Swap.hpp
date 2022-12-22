#ifndef SWAP
#define SWAP

#include <iostream>
#include <bits/stdc++.h>

template <class T>
class Swap
{
public:
    Swap()
    {
    }

    void swapBit(T &a, T &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }
};

#endif