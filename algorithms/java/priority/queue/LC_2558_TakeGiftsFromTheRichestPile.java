// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

package priority.queue;

import java.util.Comparator;
import java.util.PriorityQueue;

public class LC_2558_TakeGiftsFromTheRichestPile {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int g: gifts) {
            pq.add(g);
        }

        while (k-- > 0) {
            pq.add((int)Math.sqrt(pq.remove()));
        }

        long sum = 0;
        while (!pq.isEmpty()) {
            sum += pq.remove();
        }
        return sum;
    }
}
