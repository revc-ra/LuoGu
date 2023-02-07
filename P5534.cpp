// https://www.luogu.com.cn/problem/P5534

#include <iostream>

int main()
{
    long long a1, a2, n;

    std::cin >> a1 >> a2 >> n;

    long long d = a2 - a1;

    std::cout << n * a1 + n * (n-1)/2*d;

    return 0;
}
