// https://www.luogu.com.cn/problem/P1051

#include <iostream>
#include <string>
#include <algorithm>

void m1()
{
    std::string max_name;
    int max_scholarship = 0;
    int sum = 0;

    int N;
    std::cin >> N;
    for (int i = 0 ; i < N; i++)
    {
        std::string name;
        int avg, avg2;
        char is_lead, is_west;
        int n_paper;

        std::cin >> name >> avg >> avg2 >> is_lead >> is_west >> n_paper;

        int scholarship = 0;
        if (avg  > 80 && n_paper > 0   ) { scholarship += 8000; }
        if (avg  > 85 && avg2 > 80     ) { scholarship += 4000; }
        if (avg  > 90                  ) { scholarship += 2000; }
        if (avg  > 85 && is_west == 'Y') { scholarship += 1000; }
        if (avg2 > 80 && is_lead == 'Y') { scholarship += 850 ; }

        if (scholarship > max_scholarship)
        {
            max_scholarship = scholarship;
            max_name        = name;
        }
        sum += scholarship;
    }

    std::cout << max_name        << '\n'
              << max_scholarship << '\n'
              << sum;
}

struct stu_sch
{
    std::string name;
    int scholarship;
} a[100];

int cmp(stu_sch a, stu_sch b)
{
    return a.scholarship > b.scholarship;
}

void m2()
{
    int sum = 0;

    int N;
    std::cin >> N;
    for (int i = 0 ; i < N; i++)
    {
        std::string name;
        int avg, avg2;
        char is_lead, is_west;
        int n_paper;

        std::cin >> name >> avg >> avg2 >> is_lead >> is_west >> n_paper;

        int scholarship = 0;
        if (avg  > 80 && n_paper > 0   ) { scholarship += 8000; }
        if (avg  > 85 && avg2 > 80     ) { scholarship += 4000; }
        if (avg  > 90                  ) { scholarship += 2000; }
        if (avg  > 85 && is_west == 'Y') { scholarship += 1000; }
        if (avg2 > 80 && is_lead == 'Y') { scholarship += 850 ; }

        a[i].name        = name;
        a[i].scholarship = scholarship;

        sum += scholarship;
    }

    std::stable_sort(a, a + N, cmp);

    std::cout << (a[0].name)        << '\n'
              << (a[0].scholarship) << '\n'
              << sum;

}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // m1();
    m2();
    return 0;
}
