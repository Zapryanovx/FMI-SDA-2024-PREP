#include <iostream>
#include <vector>

class Solution {
public:
    bool canAliceWin(std::vector<int>& nums) {
        int sumOneDigits = 0;
        int sumTwoDigits = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 10)
            {
                sumOneDigits += nums[i];
            }

            else
            {
                sumTwoDigits = nums[i];
            }
        }

        return sumOneDigits != sumTwoDigits;
    }
};