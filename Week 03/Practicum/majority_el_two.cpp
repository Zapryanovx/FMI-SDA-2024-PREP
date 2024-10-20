#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<pair<int, int>> pairs;

        int count = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                count++;
            }

            else
            {
                pairs.push_back({ nums[i - 1], count });
                count = 1;
            }
        }
        pairs.push_back({ nums[nums.size() - 1], count });

        vector<int> res;
        for (int i = 0; i < pairs.size(); i++)
        {
            if (pairs[i].second > nums.size() / 3)
            {
                res.push_back(pairs[i].first);
            }
        }
        return res;
    }
};