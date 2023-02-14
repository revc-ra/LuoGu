// https://www.luogu.com.cn/problem/P1328

#include <iostream>

int vs[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0}
};

int A[200], B[200];

int main()
{
    int n, a, b;

    std::cin >> n >> a >> b;

    for (int i = 0; i < a; i++)
    {
        std::cin >> A[i];
    }

    for (int i = 0; i < b; i++)
    {
        std::cin >> B[i];
    }

    int x = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        x += vs[A[i%a]][B[i%b]];
        y += vs[B[i%b]][A[i%a]];
    }

    std::cout << x << ' ' << y;

    return 0;
}
