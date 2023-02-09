#ifndef L_LIST
#define L_LIST

#include "List.hpp"
#include "Node.hpp"

#define defaultSize 0

template <class T>
class LList : List<T>
{
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *curr;
    int size;

private:
    void Init()
    {
        curr = tail = head = new Node<T>();
        size = 0;
    }

    void RemoveAll()
    {
        while (head != NULL)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList(int size = defaultSize)
    {
        Init();
    }
    ~List() { RemoveAll(); }

public:
    void Print() const;
    void Clear()
    {
        RemoveAll();
        Init();
    }

    void Insert(const T &item)
    {
        curr->next = new Node<T>(item, curr->next);
        if (tail == curr)
            tail = curr->next;
        size++;
    }
    void Append(const T &item)
    {
        tail = tail->next
    }
    void Remove()
    {
        if (curr->next == NULL)
            return;
        T it = curr->next->element;
        Node<T> *ltemp = curr->next;
        if (tail == curr->next)
            tail = curr;
        curr->next = curr->next->next;
        delete ltemp;
        size--;
        return it;
    }
    void MoveToStart()
    {
        curr = head;
    }
    void MoveToEnd()
    {
        curr = tail;
    }
    void Prev()
    {
        if (curr == head)
            return;
        Node<T> *temp = head;
        while (temp.next != curr)
            temp = temp->next;
        curr = temp;
    }
    void Next()
    {
        if (curr != tail)
        {
            curr = curr->next;
        }
    }
    int Length() const
    {
        return size;
    }
    int CurrPos() const
    {
        Node<T> *temp = head;
        int i;
        for (i = 0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
    void MoveToPos(int pos)
    {
        if ((pos >= 0) && (pos <= size))
        {
            curr = head;
            for (int i = 0; i < pos; i++)
                curr = curr->next;
        }
    }
    const T &GetValue() const
    {
        return curr->next->element;
    }
    bool Find(T value) {}
};
#endif