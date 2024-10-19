#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> squares;
        for (size_t i = 0; i < nums.size(); i++)
        {
            squares.push_back(nums[i] * nums[i]);
        }

        sort(squares.begin(), squares.end());
        return squares;
    }
};