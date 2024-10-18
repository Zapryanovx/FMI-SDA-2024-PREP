#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {

        sort(nums.rbegin(), nums.rend());
        vector<long long> copy(nums.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            copy[i] = nums[i];
        }

        for (size_t i = 1; i < copy.size(); i++)
        {
            copy[i] += copy[i - 1];
        }

        long long score = 0;
        for (size_t i = 0; i < copy.size(); i++)
        {
            if (copy[i] > 0)
            {
                score++;
            }
        }


        return score;
    }
};