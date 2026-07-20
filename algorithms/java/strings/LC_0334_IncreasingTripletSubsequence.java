// https://leetcode.com/problems/increasing-triplet-subsequence/description

package strings;

public class LC_0334_IncreasingTripletSubsequence {
    public boolean increasingTriplet(int[] nums) {
        int first = nums[0];
        int second = Integer.MAX_VALUE;
        for (int n: nums) {
            if (n <= first) {
                first = n;
            }  else if (n <= second) {
                second = n;
            } else {
                return true;
            }
        }

        return false;
    }
}
