#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        std::sort(nums.rbegin(), nums.rend());

        return nums[0] * nums[1] - nums[nums.size() - 1] * nums[nums.size() - 2];

    }
};