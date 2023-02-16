// https://www.luogu.com.cn/problem/P1042

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

char read() {
  char ch = '\0';

  while (ch != 'W' && ch != 'L' && ch != 'E')
  {
    ch = getchar();
  }
  return ch;
}

std::string eleven_ps;     // 11-Point System
std::string twenty_one_ps; // 21-Point System

int main()
{
  char score;

  int w_11 = 0, l_11 = 0;
  int w_21 = 0, l_21 = 0;

  while((score=read()) != 'E')
  {
    if (score == 'W')
    {
      w_11++;
      w_21++;
    }
    else
    {
      l_11++;
      l_21++;
    }

    if ((w_11 >= 11 || l_11 >= 11) && abs(w_11 - l_11) >= 2)
    {
      eleven_ps += std::to_string(w_11) + ':' + std::to_string(l_11) + '\n';
      w_11 = l_11 = 0;
    }

    if ((w_21 >= 21 || l_21 >= 21) && abs(w_21 - l_21) >= 2)
    {
      twenty_one_ps += std::to_string(w_21) + ':' + std::to_string(l_21) + '\n';
      w_21 = l_21 = 0;
    }
  }

  eleven_ps     += std::to_string(w_11) + ':' + std::to_string(l_11) + '\n';
  twenty_one_ps += std::to_string(w_21) + ':' + std::to_string(l_21) + '\n';

  std::cout << eleven_ps << '\n' << twenty_one_ps;

  return 0;
}
