// https://www.luogu.com.cn/problem/P1464

#include <iostream>
#include <stdio.h>

int main()
{
    long long tuples[21][21][21];

    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            for (int k = 0; k < 21; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    tuples[i][j][k] = 1;
                }
                else if (i < j && j < k)
                {
                    tuples[i][j][k] = tuples[i][j][k - 1] + tuples[i][j - 1][k - 1] - tuples[i][j - 1][k];
                }
                else
                {
                    tuples[i][j][k] = tuples[i - 1][j][k] + tuples[i - 1][j - 1][k] + tuples[i - 1][j][k - 1] - tuples[i - 1][j - 1][k - 1];
                }
            }
        }
    }

    long long a, b, c, i, j, k;
    while (std::cin >> a >> b >> c)
    {

        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }

        i = a;
        j = b;
        k = c;

        if (a < 0 || b < 0 || c < 0)
        {
            i = j = k = 0;
        }
        else if (a > 20 || b > 20 || c > 20)
        {
            i = j = k = 20;
        }

        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, tuples[i][j][k]);
    }

    return 0;
}
