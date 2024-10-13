#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        size_t size = nums.size();
        for (int i = size - 1; i >= 2; i--)
        {
            if (nums[i] < nums[i - 1] + nums[i - 2])
            {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }

        return 0;
    }
};