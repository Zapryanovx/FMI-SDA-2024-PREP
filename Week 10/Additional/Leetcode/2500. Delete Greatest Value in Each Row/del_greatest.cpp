class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {

        vector<priority_queue<int>> pqs(grid.size());

        for (int i = 0; i < grid.size(); i++)
        {
            pqs[i] = priority_queue<int>(grid[i].begin(), grid[i].end());
        }

        int sum = 0;
        while (!pqs[0].empty())
        {
            int maxSum = 0;
            for (int i = 0; i < pqs.size(); i++)
            {
                maxSum = max(maxSum, pqs[i].top());
                pqs[i].pop();
            }

            sum += maxSum;
        }

        return sum;
    }
};