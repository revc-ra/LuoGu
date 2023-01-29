// https://www.luogu.com.cn/problem/P1014

#include <iostream>
#include <cmath>

int main()
{
    int N, n, k, p, q;

    std::cin >> N;

    n = ceil((sqrt(1+8*N)-1)/2);

    /* Another way to calculate the diagonal number `n' */
    // const double epsilon = 1e-9;
    // n = floor((sqrt(1+8*N)+1)/2-epsilon);

    k = N-n*(n-1)/2;

    if (n&1)
    {
        p = (n+1) - k;
        q = k;
    }
    else
    {
        p = k;
        q = (n+1) - k;
    }

    std::cout << p << '/' << q << std::endl;
    return 0;
}
