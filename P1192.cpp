// https://www.luogu.com.cn/problem/P1192

#include <iostream>

int dp[100001];

int main()
{
    int n, k;
    std::cin >> n >> k;

    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j > i) break;
            dp[i] = (dp[i] + dp[i - j]) % 100003;
        }
    }

    std::cout << dp[n];

    return 0;
}
