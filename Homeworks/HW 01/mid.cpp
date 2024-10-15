#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n = 0;
    cin >> n;

    vector<int> nums;

    for (size_t i = 1; i < n + 1; i++)
    {
        int temp = 0;
        cin >> temp;

        int index = nums.size();
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (nums[j] > temp)
            {
                index = j;
                break;
            }
        }

        nums.insert(nums.begin() + index, temp);

        size_t size = nums.size();
        if (i % 2 == 0)
        {

            cout << (nums[size / 2 - 1] + nums[size / 2]) / 2.00 << endl;
        }

        else
        {
            cout << nums[size / 2] << std::endl;
        }
    }

    return 0;
}
