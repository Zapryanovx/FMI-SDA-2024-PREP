// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/

package priority.queue;

import java.util.PriorityQueue;

public class LC_2357_MakeArrayZeroBySubtractingEqualAmounts {
    public int minimumOperations(int[] nums) {
        int cnt = 0;

        while (true) {
            PriorityQueue<Integer> pq = new PriorityQueue<>();
            for (int n: nums) {
                if (n > 0) {
                    pq.add(n);
                }
            }

            if (pq.isEmpty()) {
                break;
            }

            int min = pq.peek();
            for (int i = 0; i < nums.length; i++) {
                nums[i] -= min;
            }

            cnt++;
        }

        return cnt;
    }
}
