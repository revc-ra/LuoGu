// https://www.luogu.com.cn/problem/P4994

#include <iostream>

int main()
{
    int M;

    std::cin >> M;

    int n    = 1;
    int prev = 1;
    int curr = 1;

    while (prev % M != 0 || curr % M != 1)
    {
        n++;
        int tmp = (prev + curr) % M;
        prev = curr;
        curr = tmp;
    }

    std::cout << n;


    return 0;
}
