#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
    }

    std::vector<std::pair<int, int>> data(n);
    for (int i = 0; i < n; i++)
    {
        data[i].first = nums[i];
        data[i].second = i;
    }
    std::sort(data.begin(), data.end());

    int left = 0;
    int right = n - 1;
    while (left != right)
    {
        int res = data[left].first + data[right].first;
        if (res == k)
        {
            if (data[left].second > data[right].second)
            {
                std::swap(data[left].second, data[right].second);
            }
            std::cout << data[left].second << " " << data[right].second;
            break;
        }

        else if (res < k)
        {
            left++;
        }

        else if (res > k)
        {
            right--;
        }
    }

    return 0;
}
