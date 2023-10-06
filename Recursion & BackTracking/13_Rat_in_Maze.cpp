/*
Input :
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Output :
DDRDRR  DRDDRR
*/

class Solution
{
public:
    // Check if it's possible to move to a cell (row, col)
    bool canGo(vector<vector<int>> &maze, int n, int row, int col, vector<vector<int>> &lookup)
    {
        return (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1 && lookup[row][col] == 0);
    }

    // Recursive function to find paths in the maze
    void find(vector<vector<int>> &maze, int n, vector<string> &ans, string &path, int row, int col, vector<vector<int>> &lookup)
    {
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(path); // Reached the destination, add path to answers
            return;
        }

        // Try moving RIGHT
        if (canGo(maze, n, row, col + 1, lookup))
        {
            path.push_back('R');                            // Add 'R' to path
            lookup[row][col + 1] = 1;                       // Mark the lookup table cell as visited
            find(maze, n, ans, path, row, col + 1, lookup); // Recurse
            path.pop_back();                                // Backtrack: remove 'R' from path
            lookup[row][col + 1] = 0;                       // Unmark the lookup table cell
        }

        // Try moving DOWN
        if (canGo(maze, n, row + 1, col, lookup))
        {
            path.push_back('D');                            // Add 'D' to path
            lookup[row + 1][col] = 1;                       // Mark the lookup table cell as visited
            find(maze, n, ans, path, row + 1, col, lookup); // Recurse
            path.pop_back();                                // Backtrack: remove 'D' from path
            lookup[row + 1][col] = 0;                       // Unmark the lookup table cell
        }

        // Try moving LEFT
        if (canGo(maze, n, row, col - 1, lookup))
        {
            path.push_back('L');                            // Add 'L' to path
            lookup[row][col - 1] = 1;                       // Mark the lookup table cell as visited
            find(maze, n, ans, path, row, col - 1, lookup); // Recurse
            path.pop_back();                                // Backtrack: remove 'L' from path
            lookup[row][col - 1] = 0;                       // Unmark the lookup table cell
        }

        // Try moving UP
        if (canGo(maze, n, row - 1, col, lookup))
        {
            path.push_back('U');                            // Add 'U' to path
            lookup[row - 1][col] = 1;                       // Mark the lookup table cell as visited
            find(maze, n, ans, path, row - 1, col, lookup); // Recurse
            path.pop_back();                                // Backtrack: remove 'U' from path
            lookup[row - 1][col] = 0;                       // Unmark the lookup table cell
        }
    }

    // Main function to find paths in the maze
    vector<string> findPath(vector<vector<int>> &maze, int n)
    {
        vector<string> ans;                               // Store the paths
        string path;                                      // Current path
        vector<vector<int>> lookup(n, vector<int>(n, 0)); // Matrix to track visited cells

        if (maze[0][0] == 1)
        {
            lookup[0][0] = 1;                       // Start from the top-left cell
            find(maze, n, ans, path, 0, 0, lookup); // Begin recursive search
        }

        return ans; // Return all possible paths
    }
};
