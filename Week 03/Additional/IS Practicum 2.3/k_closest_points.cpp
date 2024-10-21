#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& lhs, vector<int>& rhs)
    {
        return abs(lhs[0] * lhs[0] + lhs[1] * lhs[1]) < abs(rhs[0] * rhs[0] + rhs[1] * rhs[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        sort(points.begin(), points.end(), compare);

        vector<vector<int>> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(points[i]);
        }

        return res;
    }
};