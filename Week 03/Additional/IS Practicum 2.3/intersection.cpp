#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersection;

        size_t nums1Idx = 0;
        size_t nums2Idx = 0;

        while (nums1Idx < nums1.size() && nums2Idx < nums2.size())
        {

            if (nums1[nums1Idx] == nums2[nums2Idx])
            {
                intersection.push_back(nums1[nums1Idx]);
                nums1Idx++;
                nums2Idx++;
            }

            else if (nums1[nums1Idx] < nums2[nums2Idx])
            {
                nums1Idx++;
            }

            else if (nums1[nums1Idx] > nums2[nums2Idx])
            {
                nums2Idx++;
            }

            while (nums1Idx < nums1.size() && nums1Idx > 0 && nums1[nums1Idx - 1] == nums1[nums1Idx])
            {
                nums1Idx++;
            }

            while (nums2Idx < nums2.size() && nums2Idx > 0 && nums2[nums2Idx - 1] == nums2[nums2Idx])
            {
                nums2Idx++;
            }

        }
        return intersection;
    }
};