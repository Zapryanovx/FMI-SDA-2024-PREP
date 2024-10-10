#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> days(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> days[i];
    }

    int size = days.size();
    int profit = 0;
    int i = 0;
    while (true)
    {
        if (i + 1 >= size)
        {
            break;
        }


        while (i + 1 < size && days[i + 1] < days[i])
        {
            i++;
        }

        profit -= days[i];

        while (i + 1 < size && days[i + 1] > days[i])
        {
            i++;
        }

        profit += days[i];
        i++;
    }

    std::cout << profit;


    return 0;
}