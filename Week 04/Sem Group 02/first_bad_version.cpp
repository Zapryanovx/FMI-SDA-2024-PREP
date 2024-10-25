#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int left = 0;
        int right = n;

        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                ans = mid;
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};