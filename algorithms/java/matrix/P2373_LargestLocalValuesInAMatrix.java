// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/

public class P2373_LargestLocalValuesInAMatrix {
    public int[][] largestLocal(int[][] grid) {
        int[][] local = new int[grid.length - 2][grid[0].length - 2];
        int atRow = 0;
        int atCol = 0;
        int max = 0;

        for (int row = 1; row < grid.length - 1; row++) {
            for (int col = 1; col < grid[0].length - 1; col++) {
                max = Math.max(max, grid[row - 1][col - 1]);
                max = Math.max(max, grid[row - 1][col]);
                max = Math.max(max, grid[row - 1][col + 1]);
                max = Math.max(max, grid[row][col - 1]);
                max = Math.max(max, grid[row][col]);
                max = Math.max(max, grid[row][col + 1]);
                max = Math.max(max, grid[row + 1][col - 1]);
                max = Math.max(max, grid[row + 1][col]);
                max = Math.max(max, grid[row + 1][col + 1]);
                local[atRow][atCol++] = max;
                max = 0;
            }
            atRow++;
            atCol = 0;
        }

        return local;
    }
}
