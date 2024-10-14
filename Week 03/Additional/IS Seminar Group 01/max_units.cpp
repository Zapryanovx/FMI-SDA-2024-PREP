#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    static bool compare(const vector<int>& left, const vector<int>& right)
    {
        return left[1] > right[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), compare);

        int units = 0;
        for (size_t i = 0; i < boxTypes.size(); i++)
        {
            if (truckSize == 0)
            {
                break;
            }

            if (boxTypes[i][0] >= truckSize)
            {
                units += (truckSize * boxTypes[i][1]);
                break;
            }

            else
            {
                units += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
        }

        return units;
    }
};