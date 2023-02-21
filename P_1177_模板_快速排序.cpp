// https://www.luogu.com.cn/problem/P1177

#include <iostream>
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <utility> // pair

int arr[100001];

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i]  = arr[j];
    arr[j]  = tmp;
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j-1]) { swap(arr, j, j-1); }
            else                   { break; }
        }
    }
}

typedef std::pair<int, int> pivots;

inline pivots partition(int arr[], int n)
{
    swap(arr, 0, std::rand()%n);
    int lt = 0, gt = n;
    int i = 1;

    while (i < gt)
    {
        while(i < gt && arr[i] == arr[0]) i++;

        if (i < gt && arr[i] < arr[0])
        {
            swap(arr, i, lt + 1);
            lt++;
            i++;
        }
        else if (i < gt && arr[i] > arr[0])
        {
            swap(arr, i, gt - 1);
            gt--;
        }
    }

    swap(arr, 0, lt);

    return pivots{lt, gt};
}

void quick_sort(int arr[], int n)
{
    if (n == 1 || n == 0) return;

    if (n < 30)
    {
        insertion_sort(arr, n);
        return;
    }

    pivots ps = partition(arr, n);
    quick_sort(arr, ps.first);
    quick_sort(arr + ps.second, n - ps.second);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::srand(std::time(nullptr));
    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }

    quick_sort(arr, N);

    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << ' ';
    }

    return 0;
}
