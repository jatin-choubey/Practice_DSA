/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

class Solution
{
public:
    // Helper function to generate valid combinations of parentheses
    void helper(vector<string> &ans, string &op, int open, int close, int n)
    {
        // Base case: If the current combination has reached the desired length, add it to the answer
        if (op.length() == 2 * n)
        {
            ans.push_back(op);
            return;
        }

        // Add an open parenthesis '(' if we haven't used up all allowed open parentheses
        if (open < n)
        {
            op.push_back('(');                   // Choose '('
            helper(ans, op, open + 1, close, n); // Recur with increased count of open parentheses
            op.pop_back();                       // Backtrack by removing the added '('
        }

        // Add a close parenthesis ')' if there are more open parentheses than closed parentheses
        if (close < open)
        {
            op.push_back(')');                   // Choose ')'
            helper(ans, op, open, close + 1, n); // Recur with increased count of close parentheses
            op.pop_back();                       // Backtrack by removing the added ')'
        }
    }

    // Main function to generate combinations of parentheses
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans; // Stores the generated combinations
        string op;          // Temporary string to build each combination

        // Call the helper function to generate valid combinations
        helper(ans, op, 0, 0, n); // Start with 0 open and close parentheses
        return ans;               // Return the generated combinations
    }
};
