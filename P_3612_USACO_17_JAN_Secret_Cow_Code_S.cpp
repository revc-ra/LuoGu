// https://www.luogu.com.cn/problem/P3612

#include <iostream>
#include <string>

typedef long long ll;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll N = 0;
    std::string s;

    std::cin >> s >> N;

    int n = s.length();

    // |  k-1  |                             |   k    |
    // |<----->|                             |<------>|
    // |       |                             |        |
    // +-------+------------------------+----+--------+------------------------------+
    // |                                |    |        |                              |
    // |                                |    |        |                              |
    // +--------------------------------+----+--------+------------------------------+
    // 1                                m    m+1      N                              2m                              m    m+1                                     2m

    while (N > n)
    {
        ll m = n;
        while(m < N)
        {
            m *= 2;
        }
        m /= 2;

        N -= m + 1;
        if (N == 0)
        {
            N = m;
        }
    }

    std::cout << s[N-1];
    return 0;
}
