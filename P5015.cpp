// https://www.luogu.com.cn/problem/P5015

#include <iostream>
#include <string>

int main()
{
    std::string s;

    std::getline(std::cin , s);

    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            ans++;
        }
    }

    std::cout << ans;

    return 0;
}
