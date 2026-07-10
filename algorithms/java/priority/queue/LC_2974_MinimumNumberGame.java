// https://leetcode.com/problems/minimum-number-game/description/

package priority.queue;

import java.util.PriorityQueue;

public class LC_2974_MinimumNumberGame {
    public int[] numberGame(int[] nums) {
        int[] arr = new int[nums.length];
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int n: nums) {
            pq.add(n);
        }

        for (int at = 0; at < nums.length - 1; at += 2) {
            arr[at + 1] = pq.remove();
            arr[at] = pq.remove();
        }

        return arr;
    }
}
