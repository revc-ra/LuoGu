// https://www.luogu.com.cn/problem/P1035

#include <iostream>

int main()
{
    int k;
    std::cin >> k;

    int i = 1;
    double sum = 0;

    while((sum+=1.0/i)<k){i++;};

    std::cout << i << std::endl;

    return 0;
}
