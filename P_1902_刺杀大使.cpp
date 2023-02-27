// https://www.luogu.com.cn/problem/P1902

#include <iostream>
#include <cstring>

int p[1000][1000];
bool visited[1000][1000];
int dx[4] = {1, -1,  0,  0};
int dy[4] = {0,  0,  1, -1};
int n, m;

bool dfs(int v, int x, int y)
{
    if (x == n - 1) { return true; }

    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m && !visited[x2][y2] && p[x2][y2] <= v)
        {
            visited[x2][y2] = true;
            flag = dfs(v, x2, y2);
            // visited[x2][y2] = false; // NOTE: no need to revisit!
            if (flag) { break; }
        }
    }
    return flag;
}

bool judge(int v)
{
    std::memset(visited, 0, sizeof visited);
    return dfs(v, 0, 0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;

    int min = 10000;
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> p[i][j];
            if (p[i][j] > max) { max = p[i][j]; }
            if (p[i][j] < min) { min = p[i][j]; }
        }
    }

    int lo = min, hi = max;
    while(lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (judge(mid)) {hi = mid;    }
        else            {lo = mid + 1;}
    }

    std::cout << lo;

    return 0;
}
