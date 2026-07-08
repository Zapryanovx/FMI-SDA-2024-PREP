// https://leetcode.com/problems/minimum-common-value/description/
package hashing;

import java.util.Arrays;
import java.util.Set;
import java.util.stream.Collectors;

public class LC_2540_MinimumCommonValue {
    public int getCommon(int[] nums1, int[] nums2) {
        Set<Integer> s1 = Arrays.stream(nums1)
                .boxed()
                .collect(Collectors.toSet());

        for (int n: nums2) {
            if (s1.contains(n)) {
                return n;
            }
        }

        return -1;
    }
}
