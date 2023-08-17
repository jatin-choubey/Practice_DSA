/*
980. Unique Paths III       https://leetcode.com/problems/unique-paths-iii/

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

*/

class Solution
{
public:
    int helper(vector<vector<int>> &grid, int x, int y, int zero)
    {
        if (x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] == -1)
            return 0; // Return 0 ways if invalid or we reached out of bounds while searching
        if (grid[x][y] == 2)
        {
            if (zero == -1) // Return 1 way if visited all zeros
                return 1;
            else
                return 0; // Return 0 way if not visited all zeros.
        }

        // Since we found one step to move, we decrease number of zeros and mark that cell as -1 or visited.
        zero--;
        grid[x][y] = -1;

        // Recursing for all four directions
        int totalPaths = helper(grid, x, y + 1, zero) + helper(grid, x, y - 1, zero) + helper(grid, x + 1, y, zero) + helper(grid, x - 1, y, zero);

        zero++;         // Backtrack
        grid[x][y] = 0; // Backtrack (Unmark the visited cell)

        return totalPaths;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int strRow = 0;
        int strCol = 0;
        int zero = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    strRow = i, strCol = j; // Find the row and col of the starting index
                else if (grid[i][j] == 0)
                    zero++; // Calculate the number of zeros.

        return helper(grid, strRow, strCol, zero);
    }
};