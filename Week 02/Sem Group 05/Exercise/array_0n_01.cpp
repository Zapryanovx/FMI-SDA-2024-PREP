#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
public:
    int firstMissingPositive(vector<int>& nums) {

        size_t n = nums.size();

        bool isOneIn = false;
        for (size_t i = 0; i < n; i++)
        {

            if (nums[i] == 1)
            {
                isOneIn = true;
            }

            else if (nums[i] < 1 || nums[i] > n)
            {
                nums[i] = 1;
            }

        }

        if (!isOneIn)
        {
            return 1;
        }

        for (size_t i = 0; i < n; i++)
        {
            int value = abs(nums[i]);

            if (value == nums.size())
            {
                nums[0] = -abs(nums[0]);
            }

            else
            {
                nums[value] = -abs(nums[value]);
            }
        }

        for (size_t i = 1; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i;
            }
        }

        if (nums[0] > 0)
        {
            return n;
        }
        return n + 1;

    }
};