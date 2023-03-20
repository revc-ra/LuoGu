// https://www.luogu.com.cn/problem/P1226

#include <iostream>

typedef long long ll;

ll fast_pow(int a, int b, int p)
{
    if (b == 1) { return a % p; }
    ll x = fast_pow(a, b / 2, p) % p;
    ll ans = x * x % p;

    return b & 1 ? ans * a % p : ans;
}

ll fast_pow2(int a, int b, int p)
{
    ll ans = 1, base = a;
    while(b > 0)
    {
        if (b & 1)
        {
            ans = ans * base % p;
        }
        base = base * base % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a = 0, b = 0, p = 0;
    std::cin >> a >> b >> p;

    // std::cout << a << '^' << b << " mod " << p << '=' << fast_pow(a, b, p);
    std::cout << a << '^' << b << " mod " << p << '=' << fast_pow2(a, b, p);

    return 0;
}
