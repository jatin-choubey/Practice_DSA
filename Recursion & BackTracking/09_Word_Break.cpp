/*
Given a string s and a dictionary of strings wordDict, return true if s can be
segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

EXAMPLE 1:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

EXAMPLE 2:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

class Solution
{
public:
    // Helper function to check if the string can be segmented into dictionary words
    int canBreak(string s, vector<string> &dict, int *dp, int index)
    {
        string word = "";

        // If we have reached the end of the string, return true
        if (index == s.length())
            return 1;

        // If we have already computed the result for this index, return it
        if (dp[index] != -1)
            return dp[index];

        // Iterate over the string and check if the current substring is in the dictionary
        for (int i = index; i < s.length(); i++)
        {
            word += s[i]; // Add the current charecter in the string.

            // Check if the current 'word' is in the dictionary
            if (find(dict.begin(), dict.end(), word) != dict.end())
            {
                // If the current substring is in the dictionary, check if the remaining string can be segmented
                if (canBreak(s, dict, dp, i + 1))
                    return dp[index] = 1;
            }
        }
        // If we cannot segment the string, return false
        return dp[index] = 0;
    }

    bool wordBreak(string s, vector<string> &dict)
    {
        int index = 0;
        int dp[s.length() + 1];
        memset(dp, -1, sizeof dp);
        // Call the helper function to check if the string can be segmented into dictionary words
        return canBreak(s, dict, dp, index);
    }
};
