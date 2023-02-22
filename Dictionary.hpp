#ifndef DICTIONARY
#define DICTIONARY

template <class Key, class T>
class Dictionary
{
private:
    void operator=(const Dictionary &) {}
    Dictionary(const Dictionary &) {}

public:
    Dictionary() {}
    virtual ~Dictionary() {}

public:
    virtual void Clear() = 0;
    virtual void Insert(const Key &key, const T &value) = 0;
    virtual T Remove(const Key &key) = 0;
    virtual T RemoveAny() = 0;
    virtual T Find(const Key &key) const = 0;
    virtual int Size() = 0;
};

#endif