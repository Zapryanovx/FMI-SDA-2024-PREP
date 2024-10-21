#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        std::sort(nums.rbegin(), nums.rend());

        int maxFirstThree = nums[0] * nums[1] * nums[2];
        int maxLastThree = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[0];

        cout << maxLastThree << " " << maxFirstThree;

        return maxFirstThree > maxLastThree ? maxFirstThree : maxLastThree;
    }
};