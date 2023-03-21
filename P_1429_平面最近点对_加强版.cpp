// https://www.luogu.com.cn/problem/P1429

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
Point points[200'000];

inline int comp(Point &p1, Point &p2)
{
    return p1.x < p2.x;
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

    if (end - begin == 2)
    {
        return dist_sq(begin, end-1);
    }

    int mid = (begin + end) / 2;
    ll min_sq = std::min(min_dist_sq(begin, mid), min_dist_sq(mid, end));

    int l = mid-1;
    while (begin <= l && std::pow(points[l].x-points[mid].x, 2) < min_sq)
    {
        l--;
    }

    int r = mid;
    while (r < end && std::pow(points[mid-1].x-points[r].x, 2) < min_sq)
    {
        r++;
    }

    for (int i = l+1; i <= mid - 1; i++)
    {
        for (int j = mid; j < r; j++)
        {
            min_sq = std::min(min_sq, dist_sq(i, j));
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

    std::sort(points, points+n, comp);

    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(4)
              << std::sqrt(min_dist_sq(0, n));

    return 0;
}
