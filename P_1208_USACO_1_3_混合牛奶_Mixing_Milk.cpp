// https://www.luogu.com.cn/problem/P1208

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Supply
{
    int price;
    int quantity;
};

bool comp(Supply &s1, Supply &s2)
{
    return s1.price < s2.price;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // read data
    int demand = 0, n_farmer = 0;

    cin >> demand >> n_farmer;

    vector<Supply> supplies(n_farmer);
    for (int i = 0; i < n_farmer; i++)
    {
        cin >> supplies[i].price >> supplies[i].quantity;
    }

    // sort data
    sort(supplies.begin(), supplies.end(), comp);

    // analyze data
    int expense = 0;
    for (Supply &s : supplies)
    {
        expense += s.price * min(demand, s.quantity);
        demand -= min(demand, s.quantity);
        if (demand == 0)
        {
            break;
        }
    }

    cout << expense;

    return 0;
}
