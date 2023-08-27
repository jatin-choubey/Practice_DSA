/*
NOTE: DYNAMIC PROGRAMMING CAN BE APPLIED FOR BETTER RESULTS
QUESTION: Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
Input :

S1 = a a b c c
S2 = d b b c a
S3 = a a d b b c b c a c

Output : TRUE

Explaination:
Charecters  => a a d b b c b c a c
From String => 1 1 2 2 2 2 1 1 2 1

Taking "aa" from S1
Taking "dbbc" from S2
Taking "bc" from S1
Taking "a" from S2
Taking "c" from S1

Now we see that, both the string S1 and S2 have been completely used,
and the ALTERNATING INTERLEAVES combination is equal to the target string S3.
So we return True.
*/

class Solution
{
public:
    // Recursive helper function to check if s3 can be formed by interleaving s1 and s2
    bool helper(string s1, string s2, string s3, int i, int j)
    {
        // Base case: If both s1 and s2 have been fully matched, we have successfully formed s3
        if (i == s1.size() && j == s2.size())
            return true;

        // Check if the current characters of s1 and s2 match with the corresponding character in s3
        bool s1_match = i < s1.size() && s1[i] == s3[i + j];
        bool s2_match = j < s2.size() && s2[j] == s3[i + j];

        // If both s1 and s2 match the current character in s3, we have two choices:
        // 1. Move to the next character in s1 and keep the current character in s2
        // 2. Move to the next character in s2 and keep the current character in s1
        if (s1_match && s2_match)
        {
            return helper(s1, s2, s3, i + 1, j) || helper(s1, s2, s3, i, j + 1);
        }
        // If only s1 matches the current character, move to the next character in s1
        else if (s1_match)
        {
            return helper(s1, s2, s3, i + 1, j);
        }
        // If only s2 matches the current character, move to the next character in s2
        else if (s2_match)
        {
            return helper(s1, s2, s3, i, j + 1);
        }

        // If none of the above conditions match, it means the current character in s3
        // does not match with any characters in s1 or s2, so we cannot form s3
        return false;
    }

    // Main function to check if s3 can be formed by interleaving s1 and s2
    bool isInterleave(string s1, string s2, string s3)
    {
        // If the sum of sizes of S1 and S2 are not equal to S3, straight away return false. This will also help avoid any kind of error.
        if (s1.size() + s2.size() != s3.size())
            return false;

        // Call the helper function with initial indices i = 0 and j = 0
        return helper(s1, s2, s3, 0, 0);
    }
};

// ------------------------------------ DP APPLIED -------------------------------

class Solution
{
public:
    // Helper function using dynamic programming and memoization
    bool helper(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp)
    {
        // If this subproblem has already been solved, return the cached result
        if (dp[i][j] != -1)
            return dp[i][j];

        // Base case: If both s1 and s2 have been fully matched, we have successfully formed s3
        if (i == s1.size() && j == s2.size())
        {
            dp[i][j] = true; // Cache the result for future reference
            return true;
        }

        // Check if the current characters of s1 and s2 match with the corresponding character in s3
        bool S1Match = i < s1.size() && s1[i] == s3[i + j];
        bool S2Match = j < s2.size() && s2[j] == s3[i + j];

        bool result = false;
        if (S1Match && S2Match)
        {
            // Interleave s1 and s2 in both possible ways and check if any leads to a valid interleaving
            result = helper(s1, s2, s3, i + 1, j, dp) || helper(s1, s2, s3, i, j + 1, dp);
        }
        else if (S1Match)
        {
            // Only s1 matches, so try moving ahead in s1 and continue checking
            result = helper(s1, s2, s3, i + 1, j, dp);
        }
        else if (S2Match)
        {
            // Only s2 matches, so try moving ahead in s2 and continue checking
            result = helper(s1, s2, s3, i, j + 1, dp);
        }

        dp[i][j] = result; // Cache the result for this subproblem
        return result;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        // If the total lengths of s1 and s2 do not match the length of s3, it's not possible to form s3
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        // Create a memoization table to store the results of subproblems
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        // Call the helper function with initial indices i = 0 and j = 0, along with the memoization table
        return helper(s1, s2, s3, 0, 0, dp);
    }
};
