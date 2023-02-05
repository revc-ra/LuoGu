// https://www.luogu.com.cn/problem/P1055

#include <iostream>
#include <string>

int main()
{
    char map[12] = "0123456789X";

    std::string s;
    std::cin >> s;

    int checksum = 0;
    for (int i = 0, j = 1; i < s.length() - 1; i++)
    {
        if (s[i] == '-') continue;
        checksum += (s[i] - '0') * j++;
    }

    if (map[checksum % 11] == s[s.length() - 1])
    {
        std::cout << "Right";
    }
    else
    {
        s[s.length() - 1] = map[checksum % 11];
        std::cout << s;
    }
    return 0;
}
