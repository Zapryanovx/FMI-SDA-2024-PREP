#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        vector<int> pair = intervals[0];
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (pair[1] >= intervals[i][0])
            {
                pair[1] = max(pair[1], intervals[i][1]);
            }

            else
            {
                res.push_back(pair);
                pair = intervals[i];
            }

        }

        res.push_back(pair);
        return res;
    }
};