// https://www.luogu.com.cn/problem/P5594

#include <iostream>
#include <vector>
#include <set>

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::set<int> > mocks;
    mocks.resize(k + 1, std::set<int>());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            std::cin >> a;
            mocks[a].insert(j);
        }
    }

    for (int i = 1; i <= k; i++)
    {
        std::cout << mocks[i].size() << ' ';
    }

    return 0;
}
