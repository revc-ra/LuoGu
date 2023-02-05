// https://www.luogu.com.cn/problem/P1308

#include <iostream>
#include <string>
#include <algorithm>

std::string str_tolower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::tolower(c); });
    return s;
}

int main()
{
    std::string word;
    std::string line;

    std::getline(std::cin, word);
    std::getline(std::cin, line);

    word  = str_tolower(word);
    line  = str_tolower(line);

    word  = ' ' + word + ' ';
    line  = ' ' + line + ' ';

    if (line.find(word) == std::string::npos)
    {
        std::cout << -1;
    }
    else
    {
        int cnt = 1;
        int first = line.find(word);
        int pos = first + 1;
        while ((pos = line.find(word, pos)) != std::string::npos)
        {
            cnt++;
            pos += word.size() - 1; // -1 to deal with two consecutive words, like `i I'
        }

        std::cout << cnt << ' ' << first;
    }

    return 0;
}
