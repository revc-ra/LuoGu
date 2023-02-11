// https://www.luogu.com.cn/problem/P1067

#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int coeff;
    for (int i = n; i >= 0; i--)
    {
        std::cin >> coeff;

        if (coeff == 0)
            continue; // ignore terms with coefficients of 0

        if (coeff < 0)
        {
            std::cout << '-';
        }
        else if (i < n)
        {
            std::cout << '+';
        }

        coeff = coeff > 0 ? coeff : -coeff; // take the absolute value

        if (coeff > 1 || i == 0)
        {
            std::cout << coeff;
        }

        if (i > 1)
        {
            std::cout << "x^" << i;
        }
        else if (i == 1)
        {
            std::cout << 'x';
        }
    }

    return 0;
}
