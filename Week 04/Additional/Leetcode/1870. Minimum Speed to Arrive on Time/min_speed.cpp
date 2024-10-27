#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:

    bool check(vector<int>& dist, double hour, int mid)
    {
        double time = 0.00;
        for (size_t i = 0; i < dist.size() - 1; i++)
        {
            if (dist[i] % mid != 0)
            {
                time += dist[i] / mid + 1;
            }

            else
            {
                time += dist[i] / mid;
            }

        }

        time += 1.00 * dist[dist.size() - 1] / mid;
        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        int left = 1;
        int right = 1000000000;

        int ans = INT_MAX;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(dist, hour, mid))
            {
                ans = mid;
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }

        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};