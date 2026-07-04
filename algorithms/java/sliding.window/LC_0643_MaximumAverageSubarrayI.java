// https://leetcode.com/problems/maximum-average-subarray-i/description/

public class LC_0643_MaximumAverageSubarrayI {
    public double findMaxAverage(int[] nums, int k) {
        int sumWindow = 0;

        for (int i = 0; i < k; i++) {
            sumWindow += nums[i];
        }

        double maxAvg = (double) sumWindow / k;
        for (int i = k; i < nums.length; i++) {
            sumWindow -= nums[i - k];
            sumWindow += nums[i];
            maxAvg = Math.max(maxAvg, (double) sumWindow / k);
        }

        return maxAvg;
    }
}
