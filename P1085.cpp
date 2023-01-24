// https://www.luogu.com.cn/problem/P1085

#include <iostream>

int main()
{
    int a, b;
    int max = 8;
    int max_i = 0;

    for (int i = 1; i <= 7; i++)
    {
        std::cin >> a >> b;
        if (a+b > max)
        {
            max = a+b;
            max_i = i;
        }
    }

    std::cout << max_i << std::endl;

    return 0;
}