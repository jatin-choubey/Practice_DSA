/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input:

Board-
A   B   C   E
S   J   C   S
A   D   E   E
P   S   F   A

Word - JCEFS

Output - TRUE


*/

class Solution
{
public:
    // Recursive function to search for the given word starting from cell (x, y)
    void find(vector<vector<char>> &board, string word, int index, int x, int y, bool &found)
    {
        // If the word is found or all characters in the word are matched, stop further search
        if (found == true || index == word.size())
        {
            found = true; // Mark as found
            return;       // Exit the function
        }

        // Check if the current cell is within bounds and matches the required character
        if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == word[index])
        {
            char save = board[x][y]; // Save the original character
            board[x][y] = '*';       // Mark the cell as visited

            // Explore in all four directions (right, down, left, up)
            find(board, word, index + 1, x, y + 1, found); // Right
            find(board, word, index + 1, x + 1, y, found); // Down
            find(board, word, index + 1, x, y - 1, found); // Left
            find(board, word, index + 1, x - 1, y, found); // Up

            board[x][y] = save; // Restore the cell to its original state
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        bool found = false; // Flag to indicate if the word is found
        // Iterate through each cell in the grid and start the search
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                find(board, word, 0, i, j, found); // Start search from each cell
            }
        }
        return found; // Return whether the word is found or not
    }
};

// 63 944 24 637
// 88 53 75 79 78