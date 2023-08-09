/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/

class Solution
{
public:
    // Function to check if a given string is a palindrome
    bool isPalin(string s)
    {
        string r = s;
        reverse(r.begin(), r.end()); // Reversing the string
        return s == r;               // Comparing original and reversed strings
    }

    // Helper function for palindrome partitioning
    void helper(string s, vector<vector<string>> &ans, vector<string> &op, int index)
    {
        // If we have processed the entire string, add the current partitioning to the answer
        if (index == s.size())
        {
            ans.push_back(op);
            return;
        }
        // Iterate through the remaining characters of the string
        for (int i = index; i < s.size(); i++)
        {
            // Extract a substring from the current index to 'i'
            string sub = s.substr(index, i - index + 1);
            // Check if the substring is a palindrome
            if (isPalin(sub))
            {
                op.push_back(sub);         // Add the palindrome substring to the current partition
                helper(s, ans, op, i + 1); // Recurse on the remaining part of the string
                op.pop_back();             // Backtrack by removing the last added substring
            }
        }
    }

    // Main function for palindrome partitioning
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans; // Store the final answer
        vector<string> op;          // Store the current partition
        helper(s, ans, op, 0);      // Start the partitioning process from index 0
        return ans;                 // Return the list of all valid partitionings
    }
};
