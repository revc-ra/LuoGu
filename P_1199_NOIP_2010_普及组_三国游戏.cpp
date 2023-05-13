// https://www.luogu.com.cn/problem/P1199

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int tacit[500][500];
int warrior[500];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            cin >> tacit[i][j];
            tacit[j][i] = tacit[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sort(tacit[i], tacit[i]+n);
        ans = max(ans, tacit[i][n -2]);
    }

    cout << 1 << '\n' << ans;
    return 0;
}
