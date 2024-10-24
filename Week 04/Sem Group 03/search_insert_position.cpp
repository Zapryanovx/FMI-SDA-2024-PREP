#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        auto index = lower_bound(nums.begin(), nums.end(), target);

        return index - nums.begin();
    }
};