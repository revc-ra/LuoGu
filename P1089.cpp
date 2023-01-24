// https://www.luogu.com.cn/problem/P1089

#include <iostream>

int main()
{
    int capital = 0;
    int saving  = 0;
    int budget;
    int deposit;

    for (int i = 1; i <= 12 && capital >= 0; i++)
    {
        std::cin >> budget;
        capital += 300 - budget;
        deposit  = capital / 100 * 100;
        capital -= deposit;
        saving  += deposit;

        if (capital < 0) {capital = -i;}
    }

    std::cout << (capital < 0 ? capital : capital+saving*1.2) << std::endl;

    return 0;
}
