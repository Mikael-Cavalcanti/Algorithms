#ifndef NODE
#define NODE

#include <iostream>

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