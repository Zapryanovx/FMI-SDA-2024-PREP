// https://leetcode.com/problems/relative-ranks/description/

package priority.queue;

import java.util.PriorityQueue;

public class LC_0506_RelativeRanks {
    public String[] findRelativeRanks(int[] score) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);

        for (int i = 0; i < score.length; i++) {
            pq.add(new int[]{score[i], i});
        }

        String[] res = new String[score.length];
        int cnt = 1;
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            switch(cnt) {
                case 1 -> res[curr[1]] = "Gold Medal";
                case 2 -> res[curr[1]] = "Silver Medal";
                case 3 -> res[curr[1]] = "Bronze Medal";
                default -> res[curr[1]] = String.valueOf(cnt);
            }
            cnt++;
        }

        return res;
    }
}
