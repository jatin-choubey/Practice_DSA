/*  --------------------------------  QUEUE  ---------------------------
LeetCode : 994. Rotting Oranges  https://leetcode.com/problems/rotting-oranges/

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4 (It will take 4 minute in total to rot all the fresh oranges)

X   O   O                   X   X   O                   X   X   X                   X   X   X                   X   X   X
O   O   -   after minute 1  X   O   -   after minute 2  X   X   -   after minute 3  X   X   -   after minute 4  X   X   -
-   O   O                   -   O   O                   -   O   O                   -   X   O                   -   X   X


Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

X   O   O               X   X   O               X   X   X               X   X   X               X   X   X
-   O   O   1 minute    -   O   O   2 minute    -   X   O   3 minute    -   X   X   4 minute    -   X   X    Bottom right will never rot.
O   -   O               O   -   O               O   -   O               O   -   O               O   -   X


Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

class Solution
{
public:
    // Function to check if there is a Fresh Orange, adjacent to the Rotten Orange.
    bool foundFreshOrange(int row, int col, int m, int n, set<vector<int>> &fresh, queue<vector<int>> &rotten)
    {
        if (row >= 0 && col >= 0 && row < m && col < n) // If in bounds
        {
            if (fresh.find({row, col}) != fresh.end()) // If the Orange was fresh.
            {
                fresh.erase({row, col}); // Remove it form the Fresh Section, as it will not be fresh anymore
                rotten.push({row, col}); // Now since that Orange is rotten, add it to the rotten queue.
                return true;
            }
        }

        return false;
    }
    // Function to calculate the time taken to Rot all the oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        set<vector<int>> fresh;    // Set to store the indexs (row, col) of all the 'Fresh Oranges'.
        queue<vector<int>> rotten; // Queue to store the indexes of all the 'Rotten Oranges'.

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (/*Rotten*/ grid[i][j] == 2)
                {
                    rotten.push({i, j}); // Store the indexes of all the Rotten Oranges.
                }
                else if (/*Fresh*/ grid[i][j] == 1)
                {
                    fresh.insert({i, j}); // Store the indexs of all the Fresh Oranges.
                }
            }
        }

        int time = 0;       // Initially the time is set to 0 minutes.
        bool found = false; // To check if any Fresh orange is found around the current Rotten Orange or not.

        while (!rotten.empty()) // Iterate till we have considered all the Rotten Oranges.
        {
            int rottenOranges = rotten.size(); // Current number of un-visited rotten oranges.

            for (int i = 0; i < rottenOranges; i++) // Looping untill we have not visited all those un-visited oranges, because all the Current rotten oranges will be rotting the adjacent oranges in the same minute.
            {
                vector<int> top = rotten.front();
                int row = top[0];
                int col = top[1];
                // Up (-1, 0)
                if (foundFreshOrange(row - 1, col, m, n, fresh, rotten)) // If a Fresh Orange was found on the Top of current Rotten Orange, mark Found as TRUE.
                    found = true;

                // Right  (0, +1)
                if (foundFreshOrange(row, col + 1, m, n, fresh, rotten)) // If a Fresh Orange was found on the Right of current Rotten Orange, mark Found as TRUE.
                    found = true;

                // Down   (+1, 0)
                if (foundFreshOrange(row + 1, col, m, n, fresh, rotten)) // If a Fresh Orange was found on the Bottom of current Rotten Orange, mark Found as TRUE.
                    found = true;

                // Left   (0, -1)
                if (foundFreshOrange(row, col - 1, m, n, fresh, rotten)) // If a Fresh Orange was found on the Left of current Rotten Orange, mark Found as TRUE.
                    found = true;

                rotten.pop(); // We now have checked all the Four sides of the Current Rotten Orange, so pop it out of the Queue.
            }

            if (found == true) // If even a single extra orange was rotten
            {
                time++;        // Increment time taken by one
                found = false; // Re-initilaise 'found' to 0 for the new group of rotten oranges.
            }
        }

        if (fresh.size() != 0) // If any fresh orange is stil left.
            return -1;         // Return -1

        return time; // Else return ans
    }
};