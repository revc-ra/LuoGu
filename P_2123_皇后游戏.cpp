// https://www.luogu.com.cn/problem/P2123

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

struct Hand
{
    ll left;
    ll right;
    int sign;

    bool operator <(const Hand &h) const
    {
        if (sign != h.sign)
        {
            return sign < h.sign;
        }
        else if (sign <= 0)
        {
            return left < h.left;
        }
        else
        {
            return right > h.right;
        }
    }
};

Hand hands[20'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 0;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> hands[i].left >> hands[i].right;
            if (hands[i].left < hands[i].right)
            {
                hands[i].sign = -1;
            }
            else if (hands[i].left > hands[i].right)
            {
                hands[i].sign = 1;
            }
            else
            {
                hands[i].sign = 0;
            }
        }

        sort(hands, hands+n);

        ll price = hands[0].left + hands[0].right;
        ll sum = hands[0].left;
        for (int i = 1; i < n; i++)
        {
            sum += hands[i].left;
            price = max(price + hands[i].right, sum + hands[i].right);
        }

        cout << price << endl;
    }

    return 0;
}
