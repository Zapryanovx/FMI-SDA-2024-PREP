// https://leetcode.com/problems/last-stone-weight/description/

package priority.queue;

import java.util.Comparator;
import java.util.PriorityQueue;

public class LC_1046_LastStoneWeight {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int s: stones) {
            pq.add(s);
        }

        while (pq.size() > 1) {
            int y = pq.poll();
            int x = pq.poll();
            if (x != y) {
                pq.add(y - x);
            }
        }

        return !pq.isEmpty() ? pq.peek() : 0;
    }
}
