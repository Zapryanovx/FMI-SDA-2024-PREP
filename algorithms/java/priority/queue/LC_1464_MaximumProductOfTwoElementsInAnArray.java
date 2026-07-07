// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/

package priority.queue;

import java.util.Comparator;
import java.util.PriorityQueue;

public class LC_1464_MaximumProductOfTwoElementsInAnArray {
    public int maxProduct(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int n: nums) {
            pq.add(n);
        }
        return (pq.poll() - 1) * (pq.poll() - 1);
    }
}
