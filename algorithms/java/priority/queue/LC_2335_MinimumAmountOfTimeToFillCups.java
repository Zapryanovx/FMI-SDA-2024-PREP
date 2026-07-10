// https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/

package priority.queue;

import java.util.Comparator;
import java.util.PriorityQueue;

public class LC_2335_MinimumAmountOfTimeToFillCups {
    public int fillCups(int[] amount) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        for (int n: amount) {
            pq.add(n);
        }

        int cnt = 0;
        while (pq.peek() > 0) {
            int f = pq.remove();
            int s = pq.remove();
            f--; s--; cnt++;
            pq.add(f);
            pq.add(s);
        }

        return cnt;
    }
}
