class Solution {
public:

    int ans = 0;
    int rowDirections[4] = { -1, 0, 1, 0 };
    int colDirections[4] = { 0, 1, 0, -1 };

    void dfs(vector<vector<int>>& grid, int row, int col, int empty)
    {
        if (grid[row][col] == 2)
        {
            if (empty == 0)
            {
                ans++;
            }

            return;
        }

        int temp = grid[row][col];
        grid[row][col] = -2;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + rowDirections[i];
            int nextCol = col + colDirections[i];

            if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[0].size() && grid[nextRow][nextCol] >= 0)
            {
                dfs(grid, nextRow, nextCol, empty - 1);
            }
        }

        grid[row][col] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow = 0, startCol = 0, empty = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    startRow = row;
                    startCol = col;
                }

                else if (grid[row][col] == 0)
                {
                    empty++;
                }
            }
        }


        dfs(grid, startRow, startCol, empty + 1);
        return ans;
    }

};