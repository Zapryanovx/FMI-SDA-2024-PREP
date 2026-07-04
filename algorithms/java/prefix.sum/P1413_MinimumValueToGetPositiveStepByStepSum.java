// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/

public class P1413_MinimumValueToGetPositiveStepByStepSum {
    public int minStartValue(int[] nums) {
        int minValue = Integer.MAX_VALUE;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            minValue = Math.min(minValue, sum);
        }

        if (minValue >= 1) {
            return 1;
        }
        return -minValue + 1;
    }
}
