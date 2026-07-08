// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
package arrays;

class LC_0674_LongestContinuousIncreasingSubsequence {
    public int findLengthOfLCIS(int[] nums) {
        if (nums.length == 1) {
            return 1;
        }

        int i = 1;
        int max = 1;
        int curr = 1;

        while (i < nums.length) {
            if (nums[i] <= nums[i - 1]) {
                max = Math.max(max, curr);
                curr = 0;
            }
            i++;
            curr++;
        }
        return Math.max(max, curr);
    }
}
