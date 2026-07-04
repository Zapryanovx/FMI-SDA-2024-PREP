// https://leetcode.com/problems/missing-number/description/

import java.util.HashSet;

public class LC_0268_MissingNumber {
    public int missingNumber(int[] nums) {
        HashSet<Integer> s = new HashSet<>();

        for (int n: nums) {
            s.add(n);
        }

        for (int i = 0; i <= nums.length; i++) {
            if (!s.contains(i)) {
                return i;
            }
        }

        return -1;
    }
}
