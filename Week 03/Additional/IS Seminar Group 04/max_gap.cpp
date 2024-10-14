#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());

        int max = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (max < nums[i] - nums[i - 1])
            {
                max = nums[i] - nums[i - 1];
            }
        }

        return max;
    }
};