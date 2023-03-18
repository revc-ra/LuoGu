// https://www.luogu.com.cn/problem/P1908

#include <iostream>

typedef long long ll;

int a1[5'000'00];
int a2[5'000'00];

int *cur = a1;
int *oth = a2;

int n;

ll merge(int begin, int end)
{
    ll cnt = 0;
    int mid = (begin + end) / 2;

    int i = begin, j = mid, k = begin;
    while (i < mid && j < end)
    {
        if (cur[i] <= cur[j])
        {
            oth[k++] = cur[i++];
        }
        else
        {
            oth[k++] = cur[j++];
            cnt += mid-i;
        }
    }

    while(i < mid)
    {
        oth[k++] = cur[i++];
    }
    while (j < end)
    {
        oth[k++] = cur[j++];
    }

    if (end == n) // avoid to copy elements
    {
        int *tmp = oth;
        oth      = cur;
        cur      = tmp;
    }
    else for (int i = begin; i < k; i++)
    {
        cur[i] = oth[i];
    }

    return cnt;
}

ll count_inversion(int begin, int end)
{
    if (end - begin <= 1) return 0;
    int mid = (begin + end) / 2;
    ll left  = count_inversion(begin, mid);
    ll right = count_inversion(mid, end);

    if (begin < mid && cur[mid-1] <= cur[mid]) // already sorted
    {
        return left + right;
    }
    return left + right + merge(begin, end);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> cur[i];
        oth[i] = cur[i];
    }


    std::cout << count_inversion(0, n) << '\n';
    return 0;
}
