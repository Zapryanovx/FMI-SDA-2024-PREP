#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t counter[1000000 + 1]{};

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        if (temp > 0)
        {
            if (temp > max)
            {
                max = temp;
            }

            counter[temp - 1]++;
        }

    }

    for (int i = 0; i < max; i++)
    {
        if (!counter[i])
        {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }

    std::cout << max + 1 << std::endl;
    return 0;
}