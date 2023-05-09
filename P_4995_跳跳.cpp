// https://www.luogu.com.cn/problem/P4995

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    vector<ll> heights(n);

    for (auto &h : heights)
    {
        cin >> h;
    }

    sort(heights.begin(), heights.end());

    int left = 0;
    int right = n - 1;
    int last = 0;
    ll hp = 0;

    while (left <= right)
    {
        hp += (heights[right] - last) * (heights[right] - last);
        last = heights[right];
        right--;

        if (left > right)
        {
            break;
        }

        hp += (heights[left] - last) * (heights[left] - last);
        last = heights[left];
        left++;
    }

    cout << hp;

    return 0;
}
