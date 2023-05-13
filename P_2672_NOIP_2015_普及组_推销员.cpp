// https://www.luogu.com.cn/problem/P2672

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Unit
{
    int s;
    int a;

    static bool comp(const Unit &u1, const Unit &u2)
    {
        return u1.a > u2.a;
    }
};

Unit units[100'000];
int max_s[100'001];
int sum_a[100'001];
int max_unit[100'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> units[i].s;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> units[i].a;
    }

    sort(units, units+n, Unit::comp);

    for (int i = 1; i <= n; i++)
    {
        sum_a[i] = sum_a[i-1] + units[i-1].a;
    }


    for (int i = 1; i <= n; i++)
    {
        max_s[i] = max(max_s[i-1], units[i-1].s*2);
    }

    for (int i = n-1; i >= 0; i--)
    {
        max_unit[i] = max(max_unit[i+1], units[i].a + units[i].s*2);
    }

    for (int i = 0; i < n; i++)
    {
        cout << max(sum_a[i+1]+max_s[i+1], sum_a[i]+max_unit[i]) << endl;
    }

    return 0;
}
