#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        std::sort(nums.begin(), nums.end());

        int min = 1;
        int minElIdx = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] - nums[minElIdx] > k)
            {
                min++;
                minElIdx = i;
            }
        }

        return min;
    }
};