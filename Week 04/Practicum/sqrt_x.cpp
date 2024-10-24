#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        int res = x;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (mid * mid > x)
            {
                right = mid - 1;
            }

            else
            {
                res = mid;
                left = mid + 1;
            }
        }

        return res;
    }
};