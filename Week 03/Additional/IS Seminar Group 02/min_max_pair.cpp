#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());

        int max = -1;
        for (size_t i = 0; i < nums.size() / 2; i++)
        {
            if (nums[i] + nums[nums.size() - i - 1] > max)
            {
                max = nums[i] + nums[nums.size() - i - 1];
            }
        }

        return max;
    }
};