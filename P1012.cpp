// https://www.luogu.com.cn/problem/P1012

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool n_comp(std::string s1, std::string s2)
{
    return s1 + s2 > s2 + s1;
}

int main()
{

    std::vector<std::string> a;
    int n;

    std::cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), n_comp);

    std::string sum;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    std::cout << sum;

    return 0;
}
