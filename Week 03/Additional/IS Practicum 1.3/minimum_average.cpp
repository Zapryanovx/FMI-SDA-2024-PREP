#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());

        vector<double> avg;
        size_t size = nums.size();
        int left = 0;
        int right = size - 1;

        while (left < right)
        {
            avg.push_back((nums[left] + nums[right]) / 2.00);
            left++;
            right--;
        }

        double min = avg[0];
        for (size_t i = 1; i < avg.size(); i++)
        {
            if (avg[i] < min)
            {
                min = avg[i];
            }
        }

        return min;
    }
};