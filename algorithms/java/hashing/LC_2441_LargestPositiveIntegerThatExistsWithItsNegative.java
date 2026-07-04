// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/

import java.util.HashSet;
import java.util.Set;

public class LC_2441_LargestPositiveIntegerThatExistsWithItsNegative {
    public int findMaxK(int[] nums) {
        Set<Integer> s = new HashSet<>();

        for (int n: nums) {
            s.add(n);
        }

        int max = -1;
        for (int n: s) {
            if (n > 0 && s.contains(-n)) {
                max = Math.max(max, n);
            }
        }

        return max;
    }
}
