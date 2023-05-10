// https://www.luogu.com.cn/problem/P1094

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int limit = 0;
    int n = 0;

    cin >> limit >> n;

    vector<int> prices(n);
    for (auto &p : prices)
    {
        cin >> p;
    }

    sort(prices.begin(), prices.end());

    int left = 0;
    int right = n - 1;
    int count = n;
    while(left < right)
    {
        if (prices[left] + prices[right] <= limit)
        {
            count--;
            left++;
        }
        right--;
    }

    cout << count;

    return 0;
}
