// https://www.luogu.com.cn/problem/P1307

#include <iostream>
#include <cmath>

int main()
{
    int N;
    std::cin >> N;

    if (N < 0)
    {
        std::cout << '-';
        N = -N;
    }

    // remove the trailing zeros
    while(N && (N % 10) == 0)
    {
        N /= 10;
    }

    if (N == 0)
    {
        std::cout << '0';
    }
    else
    {
        while(N)
        {
            std::cout << N % 10;
            N /= 10;
        }
    }

    return 0;
}
