#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(int lhs, int rhs)
    {
        if (lhs % 2 == 0 && rhs % 2 != 0)
        {
            return true;
        }
        
        if (lhs % 2 != 0 && rhs % 2 == 0) 
        {
            return false;
        }

        return false;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {

        sort(nums.begin(), nums.end(), compare);
        return nums;

    }
};