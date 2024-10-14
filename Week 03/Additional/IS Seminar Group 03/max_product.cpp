#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        std::sort(nums.rbegin(), nums.rend());

        return (nums[0] - 1) * (nums[1] - 1);

    }
};