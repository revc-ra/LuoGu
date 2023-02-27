// https://www.luogu.com.cn/problem/P1314

#include <iostream>
#include <cmath>

struct
{
    int w;
    int v;
}
w_v[200'000];

struct
{
    int l;
    int r;
}
l_r[200'000];

long long sum[200'001];
long long cnt[200'001];

int n, m;
long long s;

long long get_y(int W)
{
    sum[0] = 0;
    cnt[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (w_v[i-1].w >= W)
        {
            cnt[i] = cnt[i-1] + 1;
            sum[i] = sum[i-1] + w_v[i-1].v;
        }
        else
        {
            cnt[i] = cnt[i-1];
            sum[i] = sum[i-1];
        }
    }

    long long y = 0;
    for (int i = 0; i < m; i++)
    {
        y += (sum[l_r[i].r]-sum[l_r[i].l-1]) * (cnt[l_r[i].r]-cnt[l_r[i].l-1]);
    }
    return y;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        std::cin >> w_v[i].w >> w_v[i].v;
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> l_r[i].l >> l_r[i].r;
    }

    int lo = 1, hi = 1000'000;
    long long min_diff = s;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        long long y = get_y(mid);
        long long diff = y - s;

        if (std::abs(diff) < min_diff)
        {
            min_diff = std::abs(diff);
        }
        if (y - s < 0) { hi = mid - 1;}
        else           { lo = mid + 1;}
    }

    std::cout << min_diff;

    return 0;
}
