#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int minDifference(vector<int>& nums) {

        if (nums.size() <= 4)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int res = nums[nums.size() - 1] - nums[0];

        res = min(res, nums[nums.size() - 1] - nums[3]);
        res = min(res, nums[nums.size() - 2] - nums[2]);
        res = min(res, nums[nums.size() - 3] - nums[1]);
        res = min(res, nums[nums.size() - 4] - nums[0]);

        return res;
    }
};