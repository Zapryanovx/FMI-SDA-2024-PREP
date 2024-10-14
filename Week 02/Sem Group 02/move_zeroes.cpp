#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        std::vector<int> res(nums.size());
        int resIdx = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                res[resIdx++] = nums[i];
            }
        }

        for (int i = resIdx; i < nums.size(); i++)
        {
            res[i] = 0;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = res[i];
        }
    }
};
