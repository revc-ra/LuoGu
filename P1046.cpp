// https://www.luogu.com.cn/problem/P1046

#include <iostream>
#include <cmath>

int main()
{
    int distances[10], height;

    for (int i = 0; i < 10; i++)
    {
        std::cin >> distances[i];
    }

    std::cin >> height;
    height += 30;

    int counter = 0;
    for (int i = 0; i < 10; i++)
    {
        counter += distances[i] <= height;
    }

    std::cout << counter << std::endl;
    return 0;
}
