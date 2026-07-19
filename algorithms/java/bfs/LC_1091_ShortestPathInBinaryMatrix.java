// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

package bfs;

import java.util.ArrayDeque;
import java.util.Deque;

public class LC_1091_ShortestPathInBinaryMatrix {
    private final int[][] directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
            {-1, -1},
            {-1, 1},
            {1, -1},
            {1, 1}
    };

    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1) {
            return -1;
        }

        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{0, 0});

        int clearPath = 1;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int[] curr = q.pollFirst();

                if (curr[0] == grid.length - 1 && curr[1] == grid[0].length - 1) {
                    return clearPath;
                }

                for (int[] d: directions) {
                    int nextRow = curr[0] + d[0];
                    int nextCol = curr[1] + d[1];

                    if (nextRow >= 0 && nextRow < grid.length
                            && nextCol >= 0 && nextCol < grid[0].length) {
                        if (grid[nextRow][nextCol] == 0) {
                            grid[nextRow][nextCol] = 1;
                            q.add(new int[]{nextRow, nextCol});
                        }
                    }
                }
            }

            clearPath++;
        }

        return -1;
    }
}
