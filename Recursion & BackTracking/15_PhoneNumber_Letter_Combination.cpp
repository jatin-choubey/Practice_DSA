/*
Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below.
Note that 1 does not map to any letters.
*/

class Solution
{
public:
    // Helper function to generate letter combinations recursively
    void helper(string nums, vector<string> &ans, string &op, vector<string> mapp, int index)
    {
        // If we have processed all digits, add the generated combination to the answer
        if (index >= nums.length())
        {
            ans.push_back(op);
            return;
        }

        // Get the numeric value of the current digit and adjust to match the index in 'mapp'
        int n = nums[index] - '0';

        // Iterate through the characters corresponding to the current digit's letters
        for (int i = 0; i < mapp[n].length(); i++)
        {
            // Add the current letter to the combination
            op.push_back(mapp[n][i]);

            // Recursively generate combinations for the remaining digits
            helper(nums, ans, op, mapp, index + 1);

            // Backtrack by removing the last added letter for the next iteration
            op.pop_back();
        }
    }

    // Main function to generate letter combinations of a phone number
    vector<string> letterCombinations(string digits)
    {
        // Mapping of digits to corresponding letters on a phone keypad
        //                     0   1     2       3      4      5      6      7       8      9
        vector<string> mapp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // Vector to store the final combinations
        vector<string> ans;
        // String to store the temporary combination being generated
        string op;

        // If there are no digits, return an empty combination vector
        if (digits.length() == 0)
            return ans;

        // Call the helper function to generate combinations recursively
        helper(digits, ans, op, mapp, 0);

        // Return the generated combinations
        return ans;
    }
};
