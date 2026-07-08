// https://leetcode.com/problems/island-perimeter/description/

public class LC_0463_IslandPerimeter {
    public int islandPerimeter(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    return calcPerimeter(grid, i, j);
                }
            }
        }
        return 0;
    }

    private int calcPerimeter(int[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) {
            return 0;
        }
        if (grid[i][j] != 1) {
            return 0;
        }

        int p = 0;
        if (i - 1 < 0 || grid[i-1][j] == 0) {
            p++;
        }
        if (i + 1 >= grid.length || grid[i+1][j] == 0) {
            p++;
        }
        if (j - 1 < 0 || grid[i][j-1] == 0) {
            p++;
        }
        if (j + 1 >= grid[0].length || grid[i][j+1] == 0) {
            p++;
        }

        grid[i][j] = -1;

        return p
                + calcPerimeter(grid, i - 1, j)
                + calcPerimeter(grid, i + 1, j)
                + calcPerimeter(grid, i, j - 1)
                + calcPerimeter(grid, i, j + 1);
    }
}
