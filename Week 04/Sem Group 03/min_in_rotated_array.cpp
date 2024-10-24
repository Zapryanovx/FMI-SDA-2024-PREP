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
            if (nums[left] < nums[right])
            {
                ans = min(nums[left], ans);
                break;
            }

            int mid = left + (right - left) / 2;
            ans = min(ans, nums[mid]);
            if (nums[left] > nums[mid])
            {
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};