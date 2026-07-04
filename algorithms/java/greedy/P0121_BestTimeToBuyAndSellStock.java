// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class P0121_BestTimeToBuyAndSellStock {
    public int maxProfit(int[] prices) {
        int lowest = prices[0];
        int profit = -1;

        for (int price : prices) {
            lowest = Math.min(lowest, price);
            profit = Math.max(profit, price - lowest);
        }

        return profit;
    }
}