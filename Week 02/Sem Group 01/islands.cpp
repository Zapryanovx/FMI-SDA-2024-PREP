#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void markIsland(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        {
            return;
        }

        if (grid[i][j] != '1')
        {
            return;
        }

        //island found
        grid[i][j] = '0';
        markIsland(grid, i - 1, j);
        markIsland(grid, i + 1, j);
        markIsland(grid, i, j - 1);
        markIsland(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {

        size_t rows = grid.size();
        size_t cols = grid[0].size();

        int res = 0;
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == '1')
                {
                    markIsland(grid, row, col);
                    res++;
                }
            }
        }

        return res;

    }
};