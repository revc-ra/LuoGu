// https://www.luogu.com.cn/problem/P1024
// https://en.wikipedia.org/wiki/Cubic_equation
// https://artofproblemsolving.com/wiki/index.php/Location_of_Roots_Theorem

#include <iostream>
#include <iomanip>
#include <cmath>

inline double f(double a, double b, double c, double d, double x)
{
    return a*x*x*x + b*x*x + c*x + d;
}

void m1(double a, double b, double c, double d)
{
       for (double i = -100; i < 101; i++)
    {
        double begin = i;
        double end = i + 1;

        double yb = f(a, b, c, d, begin);
        double ye = f(a, b, c, d, end);

        if (yb * ye > 0 || yb != 0 && ye == 0)
        {
            continue;
        }

        double mid = (begin + end) / 2;
        double ym  = f(a, b, c, d, mid);
        while(std::abs(ym) > 1e-9)
        {
            if (yb * ym <= 0) {end   = mid;}
            else              {begin = mid;}
            mid = (begin + end) / 2;
            ym = f(a, b, c, d, mid);
        }
        std::cout << mid << ' ';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << std::setprecision(2) << std::fixed;

    m1(a, b, c, d);


    return 0;
}
