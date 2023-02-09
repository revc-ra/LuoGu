// https://www.luogu.com.cn/problem/P1025

#include <iostream>
#include <cmath>

int f(int n, int k, int u)
{
    if (k * u < n /* unable to fill up the rest */ || k > n /* over-partition */)
    {
        return 0;
    }

    if (k == 1)
    {
        return 1;
    }

    int cnt = 0;
    for (int i = 1; i <= u; i++)
    {
        cnt += f(n - i, k - 1, i);
    }

    return cnt;
}

int g(int n, int k)
{
    if (k == 0 && n == 0) return 1; // Base case
    if (k > n)            return 0; // Base case & Pruning

    if (n > k)
    {
        return g(n - 1, k - 1) + g(n - k, k);
    }
    else
    {
        return g(n - 1, k - 1);
    }
}

int dp[201][7];

int main()
{
    int n, k;
    std::cin >> n >> k;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i-1][j-1];
            if (i > j) dp[i][j] += dp[i-j][j];
        }
    }
    std::cout << dp[n][k];

    return 0;
}
