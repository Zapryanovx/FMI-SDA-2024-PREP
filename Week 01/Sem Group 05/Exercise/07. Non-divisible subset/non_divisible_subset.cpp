#include <iostream>
#include <vector>

int nums[1000000 + 1]{};
int rem[100]{};

int main()
{
    int n, k;
    std::cin >> n >> k;

    if (k == 1)
    {
        std::cout << 1;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> nums[i];
        rem[nums[i] % k]++;
    }

    int count = 0;
    for (int i = 1; i < k / 2; i++)
    {
        count += std::max(rem[i], rem[k - i]);
    }

    if (k % 2 == 0 && rem[k / 2])
    {
        count++;
    }

    else
    {
        count += std::max(rem[k / 2], rem[k - k / 2]);
    }

    if (rem[0])
    {
        count++;
    }

    std::cout << count;


    return 0;
}