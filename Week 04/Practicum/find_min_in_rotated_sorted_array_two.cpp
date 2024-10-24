#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        int ans = nums[0];
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[left] == nums[right])
            {
                ans = min(ans, nums[left]);
                left++;
                right--;
            }

            else if (nums[left] > nums[mid])
            {
                ans = min(nums[mid], ans);
                right = mid - 1;
            }

            else
            {
                ans = min(nums[left], ans);
                left = mid + 1;
            }
        }

        return ans;
    }
};