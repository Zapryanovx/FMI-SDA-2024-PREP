// https://leetcode.com/problems/snakes-and-ladders/description/

package bfs;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Set;

public class LC_0909_SnakesAndLadders {
    public int snakesAndLadders(int[][] board) {
        Set<Integer> visited = new HashSet<>();
        visited.add(1);

        Deque<Integer> q = new ArrayDeque<>();
        q.addFirst(1);

        int roll = 0;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int curr = q.pollFirst();

                if (curr == board.length * board.length) {
                    return roll;
                }

                for (int next = curr + 1; next <= Math.min(curr + 6, board.length * board.length); next++) {
                    int[] coords = findCoords(board, next);
                    int dest = next;

                    if (board[coords[0]][coords[1]] != -1) {
                        dest = board[coords[0]][coords[1]];
                    }

                    if (!visited.contains(dest)) {
                        q.add(dest);
                        visited.add(dest);
                    }
                }
            }

            roll++;
        }

        return -1;
    }

    private int[] findCoords(int[][] board, int at) {
        int row = board.length - at / board.length - 1;
        if (at % board.length == 0) {
            row++;
        }

        int col;
        if ((board.length - 1 - row) % 2 == 0) {
            col = at % board.length == 0 ? board.length - 1 : at % board.length - 1;
        } else {
            col = at % board.length == 0 ? 0 : board.length - at % board.length;
        }

        return new int[]{row, col};
    }
}
