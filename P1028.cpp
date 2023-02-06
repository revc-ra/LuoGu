// https://www.luogu.com.cn/problem/P1028

#include <iostream>

int main()
{
    int dp[1001];
    int sum[501];

    dp[1] = 1;
    sum[1] = 1;

    int n;
    std::cin >> n;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = sum[i / 2] + 1;
        sum[i] = sum[i - 1] + dp[i];
    }

    std::cout << dp[n];

    return 0;
}
