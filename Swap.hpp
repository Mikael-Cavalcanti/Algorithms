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

    void swap(T &a, T &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

#endif