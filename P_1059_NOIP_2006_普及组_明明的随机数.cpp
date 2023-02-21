// https://www.luogu.com.cn/problem/P1059

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstring>

void m1()
{
    int N;
    std::cin >> N;

    std::set<int> student_ids;
    for (int i = 0; i < N; i++)
    {
        int M;
        std::cin >> M;
        student_ids.insert(M);
    }

    std::cout << student_ids.size() << '\n';

    for (auto it=student_ids.begin(); it != student_ids.end(); it++)
    {
        std::cout << *it << ' ';
    }
}

void m2()
{
    int N;
    std::cin >> N;

    std::vector<int> student_ids;

    for (int i = 0; i < N; i++)
    {
        int M;
        std::cin >> M;
        student_ids.push_back(M);
    }

    std::sort(student_ids.begin(), student_ids.end());
    auto end = std::unique(student_ids.begin(), student_ids.end());

    std::cout << std::distance(student_ids.begin(), end) << '\n';

    for (auto it = student_ids.begin(); it != end; it++)
    {
        std::cout << *it << ' ';
    }
}

void m3()
{
    int a[1001];
    std::memset(a, 0, sizeof(a));

    int N;
    std::cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int M;
        std::cin >> M;

        if (a[M] == 0)
        {
            cnt++;
            a[M] = 1;
        }
    }

    std::cout << cnt << '\n';

    for (int i = 1; i < 1001; i++)
    {
        if (a[i])
        {
            std::cout << i << ' ';
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // m1();
    // m2();
    m3();
    return 0;
}
