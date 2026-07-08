// https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/
package sliding.window;

public class LC_2760_LongestEvenOddSubarrayWithThreshold {
    public int longestAlternatingSubarray(int[] nums, int threshold) {
        int maxSize = 0;
        int currSize = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > threshold) {
                currSize = 0;
            } else if (currSize > 0 && nums[i] % 2 == nums[i - 1] % 2) {
                currSize = (nums[i] % 2 == 0) ? 1 : 0;
            } else if (currSize == 0) {
                currSize = (nums[i] % 2 == 0) ? 1 : 0;
            } else {
                currSize++;
            }
            maxSize = Math.max(maxSize, currSize);
        }
        return maxSize;
    }
}
