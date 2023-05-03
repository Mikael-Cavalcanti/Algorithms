#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define INF 1000000000

int main()
{
    int n, k;
    int *h;
    int *dp;

    cin >> n >> k;

    h = new int[n + 1];
    dp = new int[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        dp[i] = INF;
    }

    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= min(n, i + k); j++)
        {
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n] << endl;

    delete h;
    delete dp;

    return 0;
}