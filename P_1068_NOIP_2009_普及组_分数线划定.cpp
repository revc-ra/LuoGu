// https://www.luogu.com.cn/problem/P1068

#include <iostream>
#include <algorithm>

struct id_score
{
    int id;
    int score;
};

int comp(id_score a, id_score b)
{
    if (a.score == b.score) { return a.id < b.id;       }
    else                    { return a.score > b.score; }
}

id_score a[5000];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].id >> a[i].score;
    }

    std::sort(a, a+n, comp);


    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].score >= a[m + m/2 - 1].score) {cnt++;}
        else                                    {break;}
    }

    std::cout << a[m + m/2 - 1].score << ' ' << cnt << '\n';

    for (int i = 0; i < cnt; i++)
    {
        std::cout << a[i].id << ' ' << a[i].score << '\n';
    }

    return 0;
}
