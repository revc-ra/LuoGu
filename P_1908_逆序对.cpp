// https://www.luogu.com.cn/problem/P1908

#include <iostream>
#include <algorithm>

typedef long long ll;

int a1[5'000'00];
int a2[5'000'00];

int n;

ll merge(int *arr, int *aux, int begin, int end)
{
    ll cnt = 0;
    int mid = (begin + end) / 2;

    int i = begin, j = mid, k = begin;
    while (i < mid && j < end)
    {
        if (aux[i] <= aux[j])
        {
            arr[k++] = aux[i++];
        }
        else
        {
            arr[k++] = aux[j++];
            cnt += mid-i;
        }
    }

    while(i < mid)
    {
        arr[k++] = aux[i++];
    }
    while (j < end)
    {
        arr[k++] = aux[j++];
    }

    return cnt;
}

ll count_inversion(int *arr, int *aux, int begin, int end)
{
    if (end - begin <= 1) return 0;
    int mid = (begin + end) / 2;
    ll left  = count_inversion(aux, arr, begin, mid); // sort the first half
    ll right = count_inversion(aux, arr, mid, end);   // sort the second half

    if (begin < mid && aux[mid-1] <= aux[mid]) // already sorted
    {
        std::copy(aux+begin, aux+end, arr+begin);
        return left + right;
    }
    return left + right + merge(arr, aux, begin, end);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a1[i];
        a2[i] = a1[i];
    }

    std::cout << count_inversion(a1, a2, 0, n) << '\n';
    return 0;
}
