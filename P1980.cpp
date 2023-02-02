// https://www.luogu.com.cn/problem/P1980
// https://www.cnblogs.com/revc/p/17087297.html

#include <iostream>
#include <cmath>

int main()
{
    int n, x;

    std::cin >> n >> x;

    int digits[7];

    int m = 0;  // the number of digits
    while(n > 0) // NOTE: store digits in reverse order
    {
        digits[m++] = n % 10;
        n /= 10;
    }

    int S = 0;
    for (int i = 0; i < m; i++)
    {
        int C = 0;
        int borrow = 0;
        if (x > digits[i])
        {
            if (i+1 == m) continue; /* fail to borrow */
            borrow = 1;
            digits[i+1]--;
        }

        for (int j = m - 1; j > i; j--)
        {
            C = C * 10 + digits[j];
        }

        for (int j = i - 1; j >= 0; j--)
        {
            C = C * 10 + (digits[i]==x ? digits[j] : 9);
        }

        digits[i+1] += borrow;
        S += C + 1;
    }

    if (x == 0)
    {
        int subtrahend = 1;
        while(m--)
        {
            S -= subtrahend;
            subtrahend *= 10;
        }
    }

    std::cout << S << std::endl;

    return 0;
}
