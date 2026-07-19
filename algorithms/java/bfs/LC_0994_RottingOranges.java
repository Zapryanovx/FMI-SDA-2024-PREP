// https://leetcode.com/problems/rotting-oranges/description/

package bfs;

import java.util.ArrayDeque;
import java.util.Deque;

public class LC_0994_RottingOranges {
    private int[][] directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
    };

    public int orangesRotting(int[][] grid) {
        Deque<int[]> q = new ArrayDeque<>();
        int fresh = 0;
        int minutes = 0;

        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                } else if(grid[r][c] == 2) {
                    q.add(new int[]{r, c});
                }
            }
        }

        while (!q.isEmpty() && fresh > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int[] curr = q.pollFirst();

                for (int[] d: directions) {
                    int neighbourRow = curr[0] + d[0];
                    int neighbourCol = curr[1] + d[1];

                    if (neighbourRow >= 0 && neighbourRow < grid.length
                            && neighbourCol >= 0 && neighbourCol < grid[0]. length) {
                        if (grid[neighbourRow][neighbourCol]== 1) {
                            grid[neighbourRow][neighbourCol] = 2;
                            fresh--;
                            q.add(new int[]{neighbourRow, neighbourCol});
                        }
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
}
