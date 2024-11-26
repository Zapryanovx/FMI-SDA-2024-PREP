class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n + 1, false);

        dp[1] = false;
        if (n >= 2)
        {
            dp[2] = true;
        }

        for (int i = 3; i <= n; i++)
        {
            for (int x = 1; x < i; i++)
            {
                if (i % x == 0 && !dp[i - x])
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};