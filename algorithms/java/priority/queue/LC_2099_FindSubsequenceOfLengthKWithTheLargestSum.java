// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

package priority.queue;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class LC_2099_FindSubsequenceOfLengthKWithTheLargestSum {
    public int[] maxSubsequence(int[] nums, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0]));

        for (int i = 0; i < nums.length; i++) {
            pq.add(new int[]{nums[i], i});
        }

        List<int[]> top = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            top.add(pq.remove());
        }
        top.sort((a, b) -> Integer.compare(a[1], b[1]));

        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = top.get(i)[0];
        }

        return res;
    }
}
