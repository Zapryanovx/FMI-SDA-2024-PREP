// https://leetcode.com/problems/sum-of-square-numbers/description/?envType=problem-list-v2&envId=binary-search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    bool judgeSquareSum(long long c) {

        long long left = 0;
        long long right = sqrt(c);

        while (left <= right)
        {
            long long sum = left * left + right * right;
            if (sum == c)
            {
                return true;
            }

            else if (sum > c)
            {
                right--;
            }

            else
            {
                left++;
            }
        }

        return false;
    }
};