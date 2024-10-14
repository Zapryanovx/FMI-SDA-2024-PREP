#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        size_t size = nums.size();
        k = k % size;

        std::vector<int> temp(size);
        int tempIdx = 0;
        for (int i = size - k; i < size; i++)
        {
            temp[tempIdx++] = nums[i];
        }

        for (int i = 0; i < size - k; i++)
        {
            temp[tempIdx++] = nums[i];
        }

        for (int i = 0; i < size; i++)
        {
            nums[i] = temp[i];
        }

    }
};