#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2);

        auto start = lower_bound(nums.begin(), nums.end(), target);
        auto end = upper_bound(nums.begin(), nums.end(), target);

        if (start != end)
        {
            range[0] = start - nums.begin();
            range[1] = end - nums.begin() - 1;
        }

        else
        {
            range[0] = -1;
            range[1] = -1;
        }

        return range;
    }
};