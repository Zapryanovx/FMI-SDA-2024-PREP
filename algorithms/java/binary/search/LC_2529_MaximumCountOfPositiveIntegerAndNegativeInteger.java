// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/

package binary.search;

public class LC_2529_MaximumCountOfPositiveIntegerAndNegativeInteger {
    public int maximumCount(int[] nums) {
        int lneg = 0;
        int rneg = nums.length - 1;
        while (lneg <= rneg) {
            int m = lneg + (rneg - lneg) / 2;
            if (nums[m] < 0) {
                lneg = m + 1;
            } else {
                rneg = m - 1;
            }
        }

        int lpos = lneg;
        int rpos = nums.length - 1;
        while (lpos <= rpos) {
            int m = lpos + (rpos - lpos) / 2;
            if (nums[m] > 0) {
                rpos = m - 1;
            } else {
                lpos = m + 1;
            }
        }

        return Math.max(lneg, nums.length - lpos);
    }
}
