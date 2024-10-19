#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;

        int start1 = 0;
        int start2 = 0;
        while (start1 < nums1.size() && start2 < nums2.size())
        {
            if (nums1[start1] == nums2[start2])
            {
                res.push_back(nums1[start1]);
                start1++;
                start2++;
            }

            else if (nums1[start1] > nums2[start2])
            {
                start2++;
            }

            else
            {
                start1++;
            }
        }

        return res;

    }
};