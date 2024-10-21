#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {

        std::sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        int count = 0;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum < target)
            {
                count += right - left;
                left++;
            }

            else
            {
                right--;
            }
        }

        return count;
    }
};