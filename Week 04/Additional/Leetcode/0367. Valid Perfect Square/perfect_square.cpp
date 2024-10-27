#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {

        long long left = 0;
        long long right = num;

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            if (square == num)
            {
                return true;
            }

            if (square > num)
            {
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }

        }

        return false;
    }
};