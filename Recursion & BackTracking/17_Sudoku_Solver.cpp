/*
Given a 9*9 Incomplete Sudoku.
Write a Program to Solve the SUDOKU. Such that
- Each of the digits 1-9 must occur exactly once in each row.
- Each of the digits 1-9 must occur exactly once in each column.
- Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
- '.' Represents empty cell that need to be filled
Input: board = [
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]

Output: [
["5","3","4","6","7","8","9","1","2"],
["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],
["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],
["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]
]
*/

class Solution
{
public:
    // Function to check if placing 'c' in 'row', 'col' is valid
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            // Check the current row and column for conflicts
            if (board[i][col] == c || board[row][i] == c)
            {
                return false;
            }

            // Check the 3x3 subgrid for conflicts
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            {
                return false;
            }
        }
        return true; // No conflicts, valid placement of 'c'
    }

    // Function to solve the Sudoku puzzle using backtracking
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c; // Place the digit

                            // Recur to the next empty cell
                            if (solve(board))
                            {
                                return true; // Puzzle is solved
                            }
                            else
                            {
                                board[i][j] = '.'; // Backtrack and try another digit
                            }
                        }
                    }
                    return false; // No valid digit found, need to backtrack
                }
            }
        }
        return true; // All cells filled, puzzle solved
    }

    // Function to solve the Sudoku puzzle
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
