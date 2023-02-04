// https://www.luogu.com.cn/problem/P2141

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
    std::vector<int> a;
    std::set<int> s;

    int n;

    std::cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            s.insert(a[i] + a[j]);
        }
    }

    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        cnt += s.count(a[i]);
    }

    std::cout << cnt << std::endl;

    return 0;
}
