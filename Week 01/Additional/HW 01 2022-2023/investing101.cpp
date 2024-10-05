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

    std::vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }

    int curr = 0;
    int size = values.size();
    int profit = 0;

    while (true)
    {
        if (curr + 1 >= size)
        {
            break;
        }

        while (curr + 1 < size && values[curr] > values[curr + 1])
        {
            curr++;
        }

        //bought
        profit -= values[curr];

        while (curr + 1 < size && values[curr] < values[curr + 1])
        {
            curr++;
        }

        //sold
        profit += values[curr];
        curr++;
    }

    std::cout << profit << std::endl;


    return 0;
}
