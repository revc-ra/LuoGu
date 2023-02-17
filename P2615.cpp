// https://www.luogu.com.cn/problem/P2615
// https://en.wikipedia.org/wiki/Magic_square#A_method_for_constructing_a_magic_square_of_odd_order

#include <iostream>

int matrix[39][39];

int main()
{
    int N;
    std::cin >> N;

    int i = 0, j = N/2;
    matrix[i][j] = 1;

    for (int K = 2; K <= N * N; K++)
    {
        if (matrix[(i-1+N)%N][(j+1)%N] == 0)
        {
            matrix[(i-1+N)%N][(j+1)%N] = K;
            i = i - 1 + N;
            j = j + 1;
        }
        else
        {
            matrix[(i+1)%N][j%N] = K;
            i = i + 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }

        std::cout << '\n';
    }
    return 0;
}
