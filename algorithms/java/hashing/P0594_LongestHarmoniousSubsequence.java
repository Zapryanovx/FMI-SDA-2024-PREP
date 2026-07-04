// https://leetcode.com/problems/longest-harmonious-subsequence/

import java.util.HashMap;
import java.util.Map;

public class P0594_LongestHarmoniousSubsequence {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            m.put(nums[i], m.getOrDefault(nums[i], 0) + 1);
        }

        int cnt = 0;
        for (Map.Entry<Integer, Integer> entry: m.entrySet()) {
            int left = m.getOrDefault(entry.getKey() - 1, 0);
            int right = m.getOrDefault(entry.getKey() + 1, 0);
            if (left == 0 && right == 0) {
                continue;
            }

            cnt = Math.max(cnt, Math.max(
                    entry.getValue() + left,
                    entry.getValue() + right
            ));
        }
        return cnt;
    }
}
