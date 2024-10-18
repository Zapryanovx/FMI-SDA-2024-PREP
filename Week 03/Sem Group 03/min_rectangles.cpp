#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {

        sort(points.begin(), points.end());

        int count = 1;

        int currLen = 0;
        for (size_t i = 1; i < points.size(); i++)
        {
            cout << points[i][0] << "  " << points[i - 1][0] << endl;

            if (currLen + (points[i][0] - points[i - 1][0]) <= w)
            {
                cout << currLen << " " << points[i][0] << "  " << points[i - 1][0] << endl;
                cout << endl;
                currLen += (points[i][0] - points[i - 1][0]);
            }

            else
            {
                currLen = 0;
                count++;
            }
        }

        return count;

    }
};