// https://www.luogu.com.cn/problem/P2010

#include <iostream>
#include <string>

int main()
{
    int n_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int start, end;
    std::cin >> start >> end;

    int cnt = 0;
    for (int month = 1; month <= 12; month++)
    {
        for (int day = 1; day <= n_days[month]; day++)
        {
            if (day == 10 || day == 20 || day == 30) continue;

            int date = (day   % 10) * 10000000 +
                       (day   / 10) * 1000000  +
                       (month % 10) * 100000   +
                       (month / 10) * 10000    +
                       month        * 100      +
                       day
                       ;

            if (start <= date && date <= end)
            {
                ++cnt;
            }
        }
    }

    std::cout << cnt;

    return 0;
}
