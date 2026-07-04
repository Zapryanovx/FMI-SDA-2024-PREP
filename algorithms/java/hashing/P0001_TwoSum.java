// https://leetcode.com/problems/two-sum/description/

import java.util.HashMap;
import java.util.Map;

class P0001_TwoSum {
    public int[] twoSum(int[] nums, int target) {

        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (m.containsKey(nums[i])) {
                return new int[]{m.get(nums[i]), i};
            }
            m.put(target - nums[i], i);
        }

        return new int[]{-1, -1};
    }
}