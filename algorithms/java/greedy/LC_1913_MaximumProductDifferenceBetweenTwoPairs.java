// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/
package greedy;

public class LC_1913_MaximumProductDifferenceBetweenTwoPairs {
    public int maxProductDifference(int[] nums) {
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;
        int max1 = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;

        for (int n: nums) {
            if (n >= max2) {
                max1 = max2;
                max2 = n;
            } else if (n >= max1) {
                max1 = n;
            }

            if (n <= min1) {
                min2 = min1;
                min1 = n;
            } else if (n <= min2) {
                min2 = n;
            }
        }
        return (max1 * max2) - (min1 * min2);
    }
}
