class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {

        int n = rectangles.size();
        unordered_map<double, long long> m;
        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            double ratio = 1.00 * rectangles[i][0] / rectangles[i][1];

            res += m[ratio];
            m[ratio]++;
        }

        return res;
    }
};