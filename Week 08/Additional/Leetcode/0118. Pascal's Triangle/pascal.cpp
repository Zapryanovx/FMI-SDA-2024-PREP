class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> dp(numRows);
        dp[0] = { 1 };

        for (int i = 1; i < numRows; i++)
        {
            dp[i].resize(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        return dp;
    }
};