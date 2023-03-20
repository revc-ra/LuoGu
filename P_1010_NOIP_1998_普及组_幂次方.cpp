// https://www.luogu.com.cn/problem/P1010

#include <iostream>
#include <string>

std::string dp[15];

void m1(int n)
{
    dp[0] = "2(0)";
    dp[1] = "2";

    for (int i = 2; i < 15; i++)
    {
        int j = i;
        int k = 0;
        while (j > 0)
        {
            if (j & 1)
            {
                dp[i] = dp[k] + "+" + dp[i];
            }
            j >>= 1;
            k++;
        }
        dp[i] = "2(" + dp[i].substr(0, dp[i].length()-1) +  ")";
    }

    std::string ans;

    int k = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = dp[k] + "+" + ans;
        }
        n >>= 1;
        k++;
    }
    ans = ans.substr(0, ans.length() - 1);

    std::cout << ans;

}

void m2(int num)
{
    if (num == 0) { std::cout << '0'   ; return; }
    if (num == 1) { std::cout << "2(0)"; return; }
    if (num == 2) { std::cout << '2'   ; return; }

    bool flag = false;
    for (int i = 14; i >= 0; i--)
    {
        if (num & (1 << i))
        {
            if (flag)
            {
                std::cout << '+';
            }
            if (i != 1)
            {
                std::cout << 2 << '(';
                m2(i);
                std::cout << ')';
            }
            else
            {
                std::cout << 2;
            }
            flag = true;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    std::cin >> n;

    m2(n);

    return 0;
}
