// https://www.luogu.com.cn/problem/P1036

#include <iostream>
#include <cmath>

int x[20];
int n, k;

bool is_prime(int sum)
{
    for (int i = 2; i < sqrt(sum); i++)
    {
        if (sum % i == 0)
        {
            return false;
        }
    }
    return true;
}

int f(int start, int cnt, int sum)
{
    if (cnt == 0)
    {
        return is_prime(sum) ? 1 : 0;
    }
    else
    {
        int ans = 0;
        for (int choice = start; choice < n; choice++)
        {
            ans += f(choice + 1, cnt - 1, sum + x[choice]);
        }
        return ans;
    }
}

int main()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
    }

    std::cout << f(0, k, 0);

    return 0;
}
