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

    std::string q;
    std::cin >> q;

    int max = -1;

    int first = q.find('x');
    if (first != -1)
    {

        max = std::max(max, first - 1);

    }

    int last = q.rfind('x');
    if (last != -1)
    {
        max = std::max(max, (n - 1) - last - 1);
    }

    for (int i = 0; i < n; i++)
    {
        int freeCount = 1;
        while (q[i] == '-')
        {
            freeCount++;
            i++;
        }

        if (max == -1 || freeCount / 2 - 1 > max)
        {
            max = freeCount / 2 - 1;
        }
    }

    std::cout << max;



    return 0;
}
