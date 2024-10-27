#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        sort(arr2.begin(), arr2.end());

        int counter = 0;
        for (size_t i = 0; i < arr1.size(); i++)
        {

            int left = 0;
            int right = arr2.size() - 1;

            bool isGood = true;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                int currD = abs(arr1[i] - arr2[mid]);
                if (currD <= d)
                {
                    isGood = false;
                    break;
                }

                else if (arr2[mid] > arr1[i])
                {
                    right = mid - 1;
                }

                else
                {
                    left = mid + 1;
                }
            }

            if (isGood)
            {
                counter++;
            }

        }

        return counter;
    }
};