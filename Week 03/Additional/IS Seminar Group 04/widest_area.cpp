#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        std::sort(points.begin(), points.end());

        int max = 0;
        for (size_t i = 1; i < points.size(); i++)
        {
            if (max < points[i][0] - points[i - 1][0])
            {
                max = points[i][0] - points[i - 1][0];
            }
        }

        return max;
    }
};