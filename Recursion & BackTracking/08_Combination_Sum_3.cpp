/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

*/

class Solution
{
public:
    // Helper function to find combinations of size 'k' that sum up to 'target'
    void helper(int k, int target, vector<vector<int>> &ans, vector<int> &op, int index)
    {
        // Base case: If 'k' becomes 0 and 'target' becomes 0, a valid combination is found
        if (k == 0)
        {
            if (target == 0)
                ans.push_back(op); // Store the valid combination in the answer vector
            return;
        }

        // Iterate through numbers from 'index' to 9 (both inclusive)
        for (int i = index; i <= 9; i++)
        {
            op.push_back(i); // Add the current number to the combination
            // Recursively call the helper function with reduced 'k', 'target', and updated 'op'
            helper(k - 1, target - i, ans, op, i + 1);
            op.pop_back(); // Backtrack: Remove the last added number to try other combinations
        }
    }

    // Main function to find combinations of size 'k' that sum up to 'n'
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans; // Store the final answer combinations
        vector<int> op;          // Temporary vector to store each combination

        // Call the helper function to find combinations, starting with index 1
        helper(k, n, ans, op, 1);

        return ans; // Return the list of valid combinations
    }
};
