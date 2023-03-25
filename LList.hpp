#ifndef L_LIST
#define L_LIST

#include "List.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;

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
        while (head != nullptr)
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
    ~LList() { RemoveAll(); }

public:
    void Clear() override
    {
        RemoveAll();
        Init();
    }

    void Insert(const T &item) override
    {
        curr->next = new Node<T>(item, curr->next);
        if (tail == curr)
            tail = curr->next;
        size++;
    }
    void Append(const T &item) override
    {
        tail = tail->next = new Node<T>(item);
        size++;
    }
    void Remove() override
    {
        if (curr->next == NULL)
        {
            cerr << "Empty List" << endl;
            return;
        }
        T it = curr->next->element;
        Node<T> *ltemp = curr->next;
        if (tail == curr->next)
            tail = curr;
        curr->next = curr->next->next;
        delete ltemp;
        size--;
        cout << "removed item : " << it << endl;
    }
    void MoveToStart() override
    {
        curr = head;
    }
    void MoveToEnd() override
    {
        curr = tail;
    }
    void Prev() override
    {
        if (curr == head)
            return;
        Node<T> *temp = head;
        while (temp->next != curr)
            temp = temp->next;
        curr = temp;
    }
    void Next() override
    {
        if (curr != tail)
        {
            curr = curr->next;
        }
    }
    int Length() const override
    {
        return size;
    }
    int CurrPos() const override
    {
        Node<T> *temp = head;
        int i;
        for (i = 0; curr != temp; i++)
            temp = temp->next;
        return i;
    }
    void MoveToPos(int pos) override
    {
        if ((pos < 0) && (pos >= size))
        {
            cerr << "Position out of Range" << endl;
            return;
        }

        curr = head;
        for (int i = 0; i < pos; i++)
            curr = curr->next;
    }
    const T &GetValue() const override
    {
        if (curr->next == nullptr)
            throw EmptyListException();

        return curr->next->element;
    }
    bool Find(T value) override
    {
        for (MoveToStart(); CurrPos() < Length(); Next())
        {
            if (value == GetValue())
                return true;
        }

        return false;
    }
    void Print()
    {
        cout << endl
             << "[ ";
        for (MoveToStart(); CurrPos() < Length(); Next())
        {
            cout << GetValue() << " ";
        }
        cout << "]" << endl;
    }

#pragma region Exception

    class EmptyListException : public std::exception
    {
    public:
        virtual const char *What() const noexcept
        {
            return "Error: List is empty!";
        }
    };

#pragma endregion
};
#endif