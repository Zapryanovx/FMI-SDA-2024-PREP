#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool arr[100000]{}; //100 000 limit

int main()
{
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
            arr[temp - 1] = true;
        }
    }

    for (int i = 0; i < max; i++)
    {
        if (!arr[i])
        {
            std::cout << i + 1;
            break;
        }
    }


    return 0;
}
