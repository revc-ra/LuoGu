// https://www.luogu.com.cn/problem/P1080

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;

struct Hand
{
    ll left;
    ll right;

    static bool comp(const Hand &h1, const Hand &h2)
    {
        return h1.left*h1.right < h2.left*h2.right;
    }
};

struct BigNumber
{
    static const int N = 10'001;
    int digits[N] = {0};

    BigNumber(int n)
    {
        plus(n);
    }

    void plus(int n)
    {
        digits[N-1] += n;
        for (int i = N-1; i >= 1; i--)
        {
            digits[i-1] += digits[i] / 10;
            digits[i] %= 10;
        }
    }

    void times(int n)
    {
        for (int i = N-1; i > 0; i--)
        {
            digits[i] *= n;
        }
        for (int i = N-1; i > 0; i--)
        {
            digits[i-1] += digits[i] / 10;
            digits[i] %= 10;
        }
    }

    BigNumber divide(int n)
    {
        int first = 1;
        while(digits[first] == 0)
        {
            first++;
        }

        BigNumber number(0);
        int reminder = 0;
        for (int i = first; i < N; i++)
        {
            reminder = reminder * 10 + digits[i];
            if (reminder >= n)
            {
                number.digits[i] = reminder / n;
                reminder = reminder % n;
            }
        }

        return number;
    }

    const BigNumber& max(const BigNumber &number)
    {
        for (int i = 1; i < N; i++)
        {
            if (digits[i] < number.digits[i])
            {
                return number;
            }
            else if (digits[i] > number.digits[i])
            {
                return *this;
            }
        }
        return *this;
    }

    string tostring()
    {
        int first = 1;
        while(digits[first] == 0)
        {
            first++;
        }

        string ans;
        for (int i = first; i < N; i++)
        {
            ans += digits[i] + '0';
        }

        if (ans.empty())
        {
            return "0";
        }
        else
        {
            return ans;
        }
    }
};

Hand hands[10'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    cin >> hands[0].left >> hands[0].right;
    for (int i = 1; i <= n; i++)
    {
        cin >> hands[i].left >> hands[i].right;
    }

    sort(hands+1, hands+n+1, Hand::comp);

    BigNumber max_coin(0);
    BigNumber prod(1);
    for (int i = 0; i < n; i++)
    {
        prod.times(hands[i].left);
        max_coin = prod.divide(hands[i+1].right).max(max_coin);
    }

    cout << max_coin.tostring() << endl;
    return 0;
}
