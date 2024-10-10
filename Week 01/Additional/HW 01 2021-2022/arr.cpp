#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        if (temp > 0)
        {
            v.push_back(temp);
        }
    }

    std::sort(v.begin(), v.end());

    for (unsigned i = 1; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] > 1)
        {
            std::cout << v[i - 1] + 1;
            break;
        }
    }


    return 0;
}
