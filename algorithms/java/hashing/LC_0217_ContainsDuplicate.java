// https://leetcode.com/problems/contains-duplicate/description/

import java.util.HashSet;
import java.util.Set;

public class LC_0217_ContainsDuplicate {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();

        for (int num : nums) {
            if (s.contains(num)) {
                return true;
            }
            s.add(num);
        }

        return false;
    }
}

