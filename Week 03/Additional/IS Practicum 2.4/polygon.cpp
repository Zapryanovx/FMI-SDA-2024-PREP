#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {

        sort(nums.rbegin(), nums.rend());

        vector<pair<long long, long long>> lens(nums.size());
        for (long long i = 0; i < nums.size(); i++)
        {
            lens[i].first = nums[i];
        }

        for (long long i = nums.size() - 2; i >= 0; i--)
        {
            lens[i].second = lens[i + 1].first + lens[i + 1].second;
        }

        for (long long i = 0; i < lens.size(); i++)
        {
            if (lens[i].first < lens[i].second)
            {
                return lens[i].first + lens[i].second;
            }
        }

        return -1;
    }
};