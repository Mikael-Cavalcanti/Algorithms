#ifndef BINARY_SEARCH_RECURSIVE
#define BINARY_SEARCH_RECURSIVE

template <class T>
class BSearchRecursive
{
public:
    BSearchRecursive() {}
    ~BSearchRecursive() {}
    int Search(T array[], int left, int right, T Key)
    {
        int middle;

        if (right >= left)
        {
            middle = (left + right) / 2;
            if (Key = array[middle])
                return middle;
            if (Key < array[middle])
                return Search(array, left, middle - 1, Key);
            else
                return Search(array, middle + 1, right, Key);
        }
        else
            return -1;
    }
};

#endif