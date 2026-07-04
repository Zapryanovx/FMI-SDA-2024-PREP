// https://leetcode.com/problems/majority-element/description/

import java.util.HashMap;
import java.util.Map;

public class P0169_MajorityElement {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        int majority = nums[0];

            for (int num : nums) {
            m.put(num, m.getOrDefault(num, 0) + 1);
            if (m.get(num) > m.get(majority)) {
                majority = num;
            }
        }

        return majority;
    }
}
