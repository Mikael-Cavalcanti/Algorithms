#ifndef BINARY_SEARCH
#define BINARY_SEARCH

template <class T>
class BSearch
{

public:
    BSearch()
    {
    }
    ~BSearch()
    {
    }
    bool Find(T array[], int left, int right, const T &key)
    {
        int middle;
        while (left <= right)
        {
            cout << "interation" << endl;
            middle = (left + right) / 2;
            if (key == array[middle])
                return true;
            else if (key < array[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }

        return false;
    }
};

#endif