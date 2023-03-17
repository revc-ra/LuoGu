// https://www.luogu.com.cn/problem/P1309

#include <iostream>
#include <algorithm>

struct s_w
{
    int i;
    int s;
    int w;
};

s_w a[200'000];
s_w win[100'000];
s_w lose[100'000];

int N, R, Q;

int comp(s_w v1, s_w v2)
{
    if (v1.s == v2.s) { return v1.i < v2.i; }
    else              { return v1.s > v2.s; }
}

void swap(int i, int j)
{
    s_w tmp = a[i];
    a[i]    = a[j];
    a[j]    = tmp;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> R >> Q;
    for (int i = 0; i < 2 * N; i++)
    {
        a[i].i = i;
        std::cin >> a[i].s;
    }

    for (int i = 0; i < 2 * N; i++)
    {
        std::cin >> a[i].w;
    }


    std::sort(a, a + 2*N, comp);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[j*2].w > a[j*2+1].w)
            {
                a[j*2].s++;
                win[j] = a[j*2];
                lose[j] = a[j*2+1];
            }
            else
            {
                a[j*2+1].s++;
                win[j] = a[j*2+1];
                lose[j] = a[j*2];
            }
        }
        std::merge(win, win+N, lose, lose+N, a, comp);
    }

    std::cout << a[Q-1].i + 1;

    return 0;
}
