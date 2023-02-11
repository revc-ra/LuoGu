// https://www.luogu.com.cn/problem/P1003

#include <iostream>

int rects[10001][4];

int main()
{
    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> rects[i][0] >> rects[i][1] >> rects[i][2] >> rects[i][3];
    }

    int x, y;
    std::cin >> x >> y;

    int ans = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (x < rects[i][0] || y < rects[i][1]) continue; // fall outside rectangle[i]
        if (x - rects[i][0] > rects[i][2] || y - rects[i][1] > rects[i][3]) continue; // fall outside rectangle[i]

        ans = i + 1;
        break;
    }

    std::cout << ans;

    return 0;
}
