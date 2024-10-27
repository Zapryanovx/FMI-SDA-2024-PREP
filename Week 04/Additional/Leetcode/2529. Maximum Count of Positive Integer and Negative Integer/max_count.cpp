#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int positive = distance(lower_bound(nums.begin(), nums.end(), 1), nums.end());
        int negative = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), -1));

        return max(positive, negative);

    }
};