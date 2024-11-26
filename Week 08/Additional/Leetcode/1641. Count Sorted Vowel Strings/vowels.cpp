class Solution {
public:
    int countVowelStrings(int n) {

        vector<int> dp(5, 1);

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                dp[j] += dp[j - 1];
            }
        }

        int res = 0;
        for (int i = 0; i < 5; i++)
        {
            res += dp[i];
        }

        return res;
    }
};