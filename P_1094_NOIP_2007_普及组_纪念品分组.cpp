// https://www.luogu.com.cn/problem/P1094

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int limit = 0;
    int n = 0;

    cin >> limit >> n;

    vector<int> prices(201);

    for(int i = 0; i < n; i++)
    {
        int p = 0;
        cin >> p;
        prices[p]++;
    }

    int count = 0;
    for (int i = 200; i >= 5; i--)
    {
        while(prices[i] > 0)
        {
            prices[i]--;
            for (int j = min(limit - i, limit / 2); j >= 5; j--)
            {
                if (prices[j] > 0)
                {
                    prices[j]--;
                    break;
                }
            }
            count++;
        }
    }

    cout << count;

    return 0;
}
