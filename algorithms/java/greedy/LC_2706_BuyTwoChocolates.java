// https://leetcode.com/problems/buy-two-chocolates/description/

public class LC_2706_BuyTwoChocolates {
    public int buyChoco(int[] prices, int money) {
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;

        for (int price: prices) {
            if (price <= min1) {
                min2 = min1;
                min1 = price;
            } else if (price <= min2) {
                min2 = price;
            }
        }

        int leftover = money - min1 - min2;
        return leftover >= 0 ? leftover : money;
    }
}
