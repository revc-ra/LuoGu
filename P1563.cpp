// https://www.luogu.com.cn/problem/P1563

#include <iostream>
#include <string>
#include <vector>

struct node
{
    int orientation;
    std::string occupation;
}
;

std::vector<node> nodes;

int main()
{
    int n, m;
    std::cin >> n >> m;

    int orientation;
    std::string occupation;
    for (int i = 0; i < n; i++)
    {
        std::cin >> orientation >> occupation;
        nodes.push_back({orientation, occupation});
    }

    int cur = 0;
    int step;
    for (int i = 0; i < m; i++)
    {
        std::cin >> orientation >> step;
        if (orientation == nodes[cur].orientation)
        {
            cur -= step;
        }
        else
        {
            cur += step;
        }

        if (cur > 0)
        {
            cur %= n;
        }
        else
        {
            if (cur % n == 0)
            {
                cur = 0;
            }
            else
            {
                cur = n*(-cur/n + 1) + cur;
            }
        }
    }

    std::cout << nodes[cur].occupation;

    return 0;
}
