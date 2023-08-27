/*
https://leetcode.com/problems/frog-jump/description/
403. Frog Jump
Hard
A frog is crossing a river. The river is divided into some number of units, and at each unit,
there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the
river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units.
The frog can only jump in the forward direction.

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone,
then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone,
4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
*/
class Solution
{
public:
    bool helper(vector<int> &stones, int currentPos, int jump)
    {
        // If the Current Position of FROG is at the last Index. Means we reached the last Index. Hence return TRUE.
        if (currentPos == stones.size() - 1)
            return true;

        // Iterate through every possible Position of stone on which the FROG can jump
        for (int probable = currentPos + 1; probable < stones.size(); probable++)
        {
            // Calculate the GAP between the current Stone and the next Stone.
            int gap = stones[probable] - stones[currentPos];

            // If the Gap is equal to the current jump or jump + 1 or jump - 1
            // We recursively call our helper function in hope of getting an answer.
            if (gap == jump + 1 || gap == jump || gap == jump - 1)
            {
                if (helper(stones, probable, gap))
                    return true;
            }
            else if (gap > jump + 1) // If at any point, the Gap between the current stone and next Stone exceeds jump + 1, we can safely break out because the Array is sorted.
                break;
        }

        // If we were unable to reach the end by any number of steps, return FALSE.
        return false;
    }
    bool canCross(vector<int> &stones)
    {
        return helper(stones, 0, 0);
    }
};

// -------------------------- DP ------------------------------
class Solution
{
public:
    bool helper(vector<int> &stones, int currentPos, int jump, unordered_map<int, unordered_map<int, bool>> &memo)
    {
        if (currentPos == stones.size() - 1)
            return true;

        // Check if the current state (position and jump) has already been calculated and stored in 'memo'
        if (memo.count(currentPos) && memo[currentPos].count(jump))
            return memo[currentPos][jump];

        for (int probable = currentPos + 1; probable < stones.size(); probable++)
        {
            int gap = stones[probable] - stones[currentPos];
            if (gap >= jump - 1 && gap <= jump + 1)
            {
                if (helper(stones, probable, gap, memo))
                {
                    memo[currentPos][jump] = true;
                    return true;
                }
            }
        }

        // If no valid jump is found, store the result as false in 'memo' and return false
        memo[currentPos][jump] = false;
        return false;
    }

    bool canCross(vector<int> &stones)
    {
        /* The 'memo' map is used for dynamic programming memoization to avoid redundant calculations.

        It stores information about states that have already been visited and determined to be unreachable,
        based on the current position of the frog and the jump length it has taken.

        Specifically, the memo map is an unordered map where the keys are the current positions of the frog,
        and the values associated with each key are sets of jump lengths that have been used at that
        particular position and have been determined to be unfeasible.*/

        unordered_map<int, unordered_map<int, bool>> memo;
        return helper(stones, 0, 0, memo);
    }
};