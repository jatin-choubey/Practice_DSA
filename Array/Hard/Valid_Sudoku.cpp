// Write a program to check if the given sudoku is a valid sudoku or not.
// A sudoku is valid if
// -  Every element in the row is uniquw
// -  Every element in the column is unique
// -  Every element in the sub cude of 3X3 is unique

/*
INPUT :

5  3  . | .  7  . | .  .  .
6  .  . | 1  9  5 | .  .  .
.  9  8 | .  .  . | .  6  .
--------+---------+---------
8  .  . | .  6  . | .  .  3
4  .  . | 8  .  3 | .  .  1
7  .  . | .  2  . | .  .  6
--------+---------+---------
.  6  . | .  .  . | 2  8  .
.  .  . | 4  1  9 | .  .  5
.  .  . | .  8  . | .  7  9


OUTPUT: True
*/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<string> st; // Set to store unique strings representing the row, column, and box of each number

        // Iterate over each cell of the board
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // If the current cell contains a number
                if (board[i][j] != '.')
                {
                    // Construct strings representing the row, column, and box of the current number
                    string row = "r" + to_string(i) + board[i][j];
                    string col = "c" + to_string(j) + board[i][j];
                    string box = "b" + to_string(i / 3 * 3 + j / 3) + board[i][j];

                    // Check if any of these strings is already in the set
                    if (st.find(row) == st.end() && st.find(col) == st.end() && st.find(box) == st.end())
                    {
                        // If not, insert them into the set
                        st.insert(row);
                        st.insert(col);
                        st.insert(box);
                    }
                    else
                    {
                        // If any of these strings is already in the set, return false to indicate that the board is not valid
                        return false;
                    }
                }
            }
        }
        // If all cells have been checked without returning false, return true to indicate that the board is valid
        return true;
    }
};
