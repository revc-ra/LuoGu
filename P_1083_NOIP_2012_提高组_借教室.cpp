// https://www.luogu.com.cn/problem/P1083

#include <iostream>
#include <cmath>

int r[1'000'000];
int d[1'000'000];
int s[1'000'000];
int t[1'000'000];

int diff[1'000'000];

int n, m;

inline bool judge(int mid)
{
    diff[0] = r[0];
    for (int i = 1; i < n; i++)
    {
        diff[i] = r[i] - r[i-1];
    }

    for (int i = 0; i < mid; i++)
    {
        diff[s[i]-1] -= d[i];
        if (t[i] < n)
        {
           diff[t[i]] += d[i];
        }
    }

    if (diff[0] < 0) { return false; }
    for (int i = 1; i < n; i++)
    {
        diff[i] += diff[i-1];
        if (diff[i] < 0) return false;
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> r[i];
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> d[i] >> s[i] >> t[i];
    }

    int lo = 0, hi = m;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (judge(mid)) { lo = mid + 1;}
        else            { hi = mid;    }
    }

    if (lo == m)
    {
        std::cout << 0;
    }
    else
    {
        std::cout << -1 << '\n' << hi;
    }

    return 0;
}
