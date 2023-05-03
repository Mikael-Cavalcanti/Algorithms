#ifndef KNAPSACK
#define KNAPSACK

#include <cmath>

class Knapsack
{
private:
    int **F;
    int n, W;

public:
    Knapsack(const int items, const int capacity)
    {
        n = items + 1;
        W = capacity + 1;

        F = new int *[n];
        for (int i = 0; i < n; i++)
            F[i] = new int[W];
    }
    ~Knapsack()
    {
        for (int i = 0; i < n; i++)
            delete[] F[i];
        delete[] F;
    }

public:
    int BottomUp(const int n, const int W, const int *w, const int *v)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i == 0 || j == 0)
                    F[i][j] = 0;
                else if (w[i] <= j)
                    F[i][j] = std::max(F[i - 1][j], v[i] + F[i - 1][j - w[i]]);
                else
                    F[i][j] = F[i - 1][j];
            }
        }

        return F[n][W];
    }
};

#endif