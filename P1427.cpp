// https://www.luogu.com.cn/problem/P1427

#include <iostream>

int main()
{
    int numbers[101];

    int n;
    for(n = 0; std::cin >> numbers[n]; n++);
    for(int i = n - 2; i >= 0; i--)
    {
        std::cout << numbers[i] << ' ';
    }

    return 0;
}
