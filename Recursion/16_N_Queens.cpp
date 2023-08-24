/*
Given an N*N chess board. In how many ways can you place N Queens in such a way that NO TWO QUEENS attack each other.
Eg. Input = 4

OUTPUT :
   Option 1                    Option 2
.   Q   .   .               .   .   Q   .
.   .   .   Q               Q   .   .   .
Q   .   .   .               .   .   .   Q
.   .   Q   .               .   Q   .   .

*/

// ----------- APPROACH 1 (Straight Forward) --------------
class Solution
{
public:
    // Function to check if it's safe to place a queen at a particular position
    bool isSafe(vector<string> &board, int row, int col)
    {
        int rowdup = row;
        int coldup = col;

        // Check upper diagonal
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false; // Not Safe to Place the Queen
            row--;
            col--;
        }

        // Check horizontally on the SAME ROW
        row = rowdup;
        col = coldup;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false; // Not Safe to Place the Queen
            col--;
        }

        // Check lower diagonal
        row = rowdup;
        col = coldup;
        while (row < board.size() && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false; // Not Safe to Place the Queen
            row++;
            col--;
        }

        return true; // It's safe to place a queen at this position
    }

    // Helper function to solve NQueens problem using backtracking
    void helper(vector<string> board, int col, vector<vector<string>> &ans)
    {
        if (col == board.size())
        {
            ans.push_back(board); // All queens are placed successfully. Hence add the solution to the answer
            return;
        }

        for (int row = 0; row < board.size(); row++)
        {
            if (isSafe(board, row, col))
            {
                board[row][col] = 'Q';       // Place the queen
                helper(board, col + 1, ans); // Recur for the next column
                board[row][col] = '.';       // Backtrack and remove the queen from this position
            }
        }
    }

    // Main function to solve NQueens problem
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;              // To store all solutions
        vector<string> board(n, string(n, '.')); // Initialize the board with empty rows
        helper(board, 0, ans);                   // Start solving the NQueens problem from column 0
        return ans;                              // Return all possible solutions
    }
};

// ---------------- APPROACH 2 - (FASTER) - (Extra Space) --------------------------
// Uses Extra Space for Horizontal, Upper Diagonal, Lower Diagonal Queen occourences

class Solution
{
public:
    // Helper function to solve NQueens problem using backtracking
    void solve(int n, int col, vector<vector<string>> &ans, vector<string> &board, vector<int> &h, vector<int> &ud, vector<int> &ld)
    {
        if (col == n)
        {
            ans.push_back(board); // All queens are placed successfully, add the solution to the answer
            return;
        }
        for (int row = 0; row < n; row++)
        {
            // Check if the current position is safe to place a queen
            if (h[row] == 0 && ud[n - 1 + col - row] == 0 && ld[row + col] == 0)
            {
                board[row][col] = 'Q';     // Place the queen
                h[row] = 1;                // Mark the horizontal as occupied
                ud[n - 1 + col - row] = 1; // Mark the upper diagonal as occupied
                ld[row + col] = 1;         // Mark the lower diagonal as occupied

                // Recur for the next column
                solve(n, col + 1, ans, board, h, ud, ld);

                // Backtrack and remove the queen from this position
                board[row][col] = '.';
                h[row] = 0;                // Mark the horizontal as unoccupied
                ud[n - 1 + col - row] = 0; // Mark the upper diagonal as unoccupied
                ld[row + col] = 0;         // Mark the lower diagonal as unoccupied
            }
        }
    }

    // Main function to solve NQueens problem
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;              // To store all solutions
        vector<string> board(n, string(n, '.')); // Initialize the board with empty rows
        vector<int> h(n, 0);                     // Track occupied horizontal rows
        vector<int> ud(2 * n - 1, 0);            // Track occupied upper diagonals
        vector<int> ld(2 * n - 1, 0);            // Track occupied lower diagonals
        solve(n, 0, ans, board, h, ud, ld);      // Start solving the NQueens problem from column 0
        return ans;                              // Return all possible solutions
    }
};