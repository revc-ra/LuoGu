// https://www.luogu.com.cn/problem/P4343

#include <iostream>
#include <cmath>

int a[1'000'00];
int l, k;

typedef long long ll;
constexpr ll MAX  = 1ll << 62;

inline int judge(ll n)
{
    ll sum = 0;
    int cnt = 0;
    for (int i = 0; i < l; i++)
    {
        sum += a[i];
        sum = sum > 0 ? sum : 0;
        if (sum >= n)
        {
            cnt++;
            sum = 0;
        }
        if (cnt > k)  { return 1; }
    }

    if      (cnt > k) { return  1; }
    else if (cnt < k) { return -1; }
    else              { return  0; }
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> l >> k;

    for (int i = 0; i < l; i++)
    {
        std::cin >> a[i];
    }

    ll lo = 1, hi = MAX;
    ll min = MAX + 1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        int flag = judge(mid);
        if      (flag == 0) { hi = mid - 1; min = std::min(min, mid); }
        else if (flag <  0) { hi = mid - 1;}
        else                { lo = mid + 1;}
    }

    if (min == MAX + 1)
    {
        std::cout << -1;
        return 0;
    }

    lo = 1, hi = MAX;
    ll max = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        int flag = judge(mid);
        if      (flag == 0) { lo = mid + 1; max = std::max(max, mid); }
        else if (flag <  0) { hi = mid - 1;}
        else                { lo = mid + 1;}
    }

    std::cout << min << ' ' << max;
    return 0;
}
