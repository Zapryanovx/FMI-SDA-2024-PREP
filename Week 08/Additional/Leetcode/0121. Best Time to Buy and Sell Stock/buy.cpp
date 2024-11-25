class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() < 2)
        {
            return 0;
        }

        int minPrice = INT_MAX;
        int maxProfit = -1;

        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);

            int profit = prices[i] - minPrice;

            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};