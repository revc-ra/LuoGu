// https://www.luogu.com.cn/problem/P3952

#include <iostream>
#include <string>
#include <cmath>

int main()
{
    int PN;
    std::cin >> PN;

    for (int i = 0; i < PN; i++)
    {
        int LN;
        std::string complexity;
        std::cin >> LN >> complexity;

        char stack_var[100];
        int  stack_exp[100];
        stack_exp[0] = 0;
        int p = 1;

        int conj_exponent; // conjectural
        if (complexity == "O(1)")
        {
            conj_exponent = 0;
        }
        else
        {
            conj_exponent = std::stoi(complexity.substr(4, complexity.find_last_of(')')-4));
        }

        int real_exponent = 0;

        for (int j = 0; j < LN; j++)
        {
            char type, var;
            std::string begin, end;

            std::cin >> type;
            if (type == 'E')
            {
                if (p == 1)
                {
                    std::string s;
                    for (; j < LN; j++)
                    {
                        std::getline(std::cin, s); // read the leftovers
                    }
                    goto ERROR;
                }
                --p;
            }
            else
            {
                std::cin >> var >> begin >> end;
                for (int k = 1; k < p; k++)
                {
                    if (stack_var[k] == var)
                    {
                        std::string s;
                        for (; j < LN; j++)
                        {
                            std::getline(std::cin, s); // read the leftovers
                        }
                        goto ERROR;
                    }
                }

                stack_var[p] = var;

                if (begin != "n" && end == "n" && stack_exp[p-1] >= 0)
                {
                    stack_exp[p] = stack_exp[p-1] + 1;
                }
                else if (begin == "n" && end != "n")
                {
                    stack_exp[p] = -1;
                }
                else if (begin != "n" && end != "n" && std::stoi(begin) > std::stoi(end))
                {
                    stack_exp[p] = -1;
                }
                else
                {
                    stack_exp[p] = stack_exp[p-1];
                }

                real_exponent = std::max(real_exponent, stack_exp[p]);
                p++;
            }
        } // LN
        if (p > 1)
        {
            ERROR:
            std::cout << "ERR\n";
        }
        else
        {
            if (real_exponent == conj_exponent)
            {
                std::cout << "Yes\n";
            }
            else
            {
                std::cout << "No\n";
            }
        }
    } // PN

    return 0;
}
