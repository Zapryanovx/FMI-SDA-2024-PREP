#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());

        vector<int> res;
        int idx = 0;
        while (idx < nums.size())
        {
            int minAlice = nums[idx++];
            int minBob = nums[idx++];

            res.push_back(minBob);
            res.push_back(minAlice);
        }

        return res;
    }
};