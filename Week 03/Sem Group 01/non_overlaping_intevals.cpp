#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& lhs, vector<int>& rhs)
    {
        if (lhs[1] == rhs[1])
        {
            return lhs[0] < rhs[0];
        }
        return lhs[1] < rhs[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), compare);

        int end = intervals[0][1];
        int count = 0;
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (end > intervals[i][0])
            {
                count++;
            }

            else
            {
                end = intervals[i][1];
            }
        }

        return count;
    }
};