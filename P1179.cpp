// https://www.luogu.com.cn/problem/P1179

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    int L, R;
    std::cin >> L >> R;

    int ans = 0;
    for (int i = L; i <= R; i++)
    {
        std::stringstream s;
        s << i;

        std::string str;
        str = s.str();
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '2')
            {
                ans++;
            }
        }
    }

    std::cout << ans;

    return 0;
}
