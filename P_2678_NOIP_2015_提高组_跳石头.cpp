// https://www.luogu.com.cn/problem/P2678

#include <iostream>

int a[50000];

inline bool check(int d, int N, int M)
{
    int source = 0;
    int cnt = 0;
    for (int i = 0; i <= N; i++)
    {
        if (a[i] - source < d) { cnt++;        }
        else                   { source = a[i];}
    }

    if (cnt > M) { return false; }
    else         { return true;  }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int L, M, N;
    std::cin >> L >> N >> M;

    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }
    a[N] = L;

    int lo = 0, hi = L;
    while(lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        if (check(mid, N , M)) { lo = mid;    }
        else                   { hi = mid - 1;}
    }

    std::cout << lo;
    return 0;
}
