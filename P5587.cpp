// https://www.luogu.com.cn/problem/P5587

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main()
{
    std::vector<std::string> sample;
    std::vector<std::string> input;

    std::string line;
    while (std::getline(std::cin, line) && line != "EOF")
    {
        std::string clean;
        for (int i = 0; i < line.length(); i++)
        {

            if (line[i] != '<')
            {
                clean.push_back(line[i]);
            }
            else if (clean.length() > 0)
            {
                clean.pop_back();
            }
        }
        sample.push_back(clean);
    }

    while (std::getline(std::cin, line) && line != "EOF")
    {
        std::string clean;
        for (int i = 0; i < line.length(); i++)
        {

            if (line[i] != '<')
            {
                clean.push_back(line[i]);
            }
            else if (clean.length() > 0)
            {
                clean.pop_back();
            }
        }

        input.push_back(clean);
    }

    double elapse;
    std::cin >> elapse;

    int cnt = 0;
    for (int i = 0; i < std::min(sample.size(), input.size()); i++)
    {
        for (int j = 0; j < std::min(sample[i].length(), input[i].length()); j++)
        {
            if (sample[i][j] == input[i][j])
            {
                cnt++;
            }
        }
    }

    std::cout << std::round(cnt / elapse * 60.0);

    return 0;
}
