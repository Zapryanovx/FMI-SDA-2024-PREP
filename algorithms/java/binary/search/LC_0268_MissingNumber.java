// https://leetcode.com/problems/missing-number/description/

package binary.search;

import java.util.Arrays;

public class LC_0268_MissingNumber {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int l = 0;
        int r = nums.length - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (m == nums[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
}
