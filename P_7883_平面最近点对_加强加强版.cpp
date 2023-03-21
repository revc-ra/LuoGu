// https://www.luogu.com.cn/problem/P7883


#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <algorithm>

typedef long long ll;

struct Point
{
    ll x;
    ll y;
};

int n;
Point points[400'000];
int y[400'000];
int y2[400'000];
int temp[400'000];

inline int comp(Point &p1, Point &p2)
{
    return p1.x < p2.x;
}

inline int comp2(int i, int j)
{
    return points[i].y < points[j].y;
}

inline ll dist_sq(int p1, int p2)
{
    ll x_diff = points[p1].x - points[p2].x;
    ll y_diff = points[p1].y - points[p2].y;
    return x_diff*x_diff+y_diff*y_diff;
}

ll min_dist_sq(int begin, int end)
{
    if (end - begin == 1)
    {
        return __LONG_LONG_MAX__;
    }

    int mid = (begin + end) / 2;
    std::copy(y+begin, y+end, temp+begin);
    std::merge(temp+begin, temp+mid, temp+mid, temp+end, y+begin, comp2);

    if (end - begin == 2)
    {
        return dist_sq(begin, end-1);
    }

    ll min_sq = std::min(min_dist_sq(begin, mid), min_dist_sq(mid, end));

    int cnt = 0;
    for (int i = begin; i < end; i++)
    {
        if (std::pow(points[y[i]].x - points[mid].x, 2) < min_sq)
        {
            y2[cnt++] = y[i];
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        for (int j = i+1; j < cnt && std::pow(points[y2[j]].y - points[y2[i]].y, 2) < min_sq; j++)
        {
            min_sq = std::min(min_sq, dist_sq(y2[i], y2[j]));
        }
    }
    return min_sq;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> points[i].x >> points[i].y;
    }

    for(int i = 0; i < n; i++)
    {
        y[i] = i;
    }

    std::sort(points, points+n, comp);

    std::cout << min_dist_sq(0, n) << '\n';

    return 0;
}
