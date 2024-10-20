#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        vector<pair<int, int>> pairs(nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            pairs[i].first = nums[i];
            pairs[i].second = i;
        }

        sort(pairs.begin(), pairs.end());

        for (size_t i = 1; i < nums.size(); i++)
        {
            if (pairs[i].first == pairs[i - 1].first)
            {
                if (abs(pairs[i].second - pairs[i - 1].second) <= k)
                {
                    return true;
                }
            }
        }

        return false;
    }
};