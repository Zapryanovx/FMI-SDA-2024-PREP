#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:

    int check(vector<int>& nums, int mid)
    {
        return distance(lower_bound(nums.begin(), nums.end(), mid), nums.end());
    }

    int specialArray(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = *max_element(nums.begin(), nums.end());

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int countGreater = check(nums, mid);

            cout << mid << " " << countGreater << endl;
            if (countGreater == mid)
            {
                return mid;
            }

            else if (countGreater > mid)
            {
                left = mid + 1;
            }

            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};