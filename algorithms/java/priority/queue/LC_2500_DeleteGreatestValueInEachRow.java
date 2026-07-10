// https://leetcode.com/problems/delete-greatest-value-in-each-row/description/

package priority.queue;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class LC_2500_DeleteGreatestValueInEachRow {
    public int deleteGreatestValue(int[][] grid) {
        List<PriorityQueue<Integer>> rows = new ArrayList<>();

        for (int row = 0; row < grid.length; row++) {
            PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
            for (int col = 0; col < grid[0].length; col++) {
                pq.add(grid[row][col]);
            }
            rows.add(pq);
        }

        int sum = 0;
        while (!rows.get(0).isEmpty()) {
            int max = Integer.MIN_VALUE;
            for (int row = 0; row < grid.length; row++) {
                max = Math.max(max, rows.get(row).remove());
            }
            sum += max;
        }

        return sum;
    }
}
