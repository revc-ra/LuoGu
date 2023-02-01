// https://www.luogu.com.cn/problem/P1047

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int length, m;
    std::vector<std::vector<int> > intervals;
    std::cin >> length >> m;

    intervals.resize(m, std::vector<int>(2));

    for (int i = 0; i < m; i++)
    {
        std::cin >> intervals[i][0] >> intervals[i][1];
    }

    std::sort(intervals.begin(), intervals.end());

    int start = 0, end = -1;

    for (int i = 0; i < m; i++)
    {
        if (intervals[i][0] <= end)
        {
            end = std::max(end, intervals[i][1]);
        }
        else
        {
            length -= end - start + 1;
            start = intervals[i][0];
            end   = intervals[i][1];
        }
    }

    length -= end - start;

    std::cout << length << std::endl;

    return 0;
}
