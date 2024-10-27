#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool check(vector<int>& piles, int mid, int h)
    {
        long long currHours = 0;
        for (size_t i = 0; i < piles.size(); i++)
        {
            if (piles[i] % mid == 0)
            {
                currHours += piles[i] / mid;
            }

            else
            {
                currHours += piles[i] / mid + 1;
            }
        }

        return currHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(piles, mid, h))
            {
                ans = min(mid, ans);
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