// Monotonic Stack, Hash Table
// LEETCODE : 316. Remove Duplicate Letters https://leetcode.com/problems/remove-duplicate-letters/description/
/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is
the smallest in lexicographical order among all possible results.

NOTE: We need to make sure that the order is maintianed.

Example 1:

Input: s = "bcabc"
Output: "abc"


Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

*/
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        // Create a frequency map to count the occurrences of each character in the string.
        vector<int> freq(26, 0);

        // Count the frequency of each character in the string.
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 97]++;
        }

        // Create a boolean array 'taken' to track whether a character is already in the stack.
        // 'taken' is an array of 26 booleans (for each letter of the alphabet), initialized to false.
        vector<bool> taken(26, false);

        // Create an empty stack of characters.
        stack<char> st;

        // Iterate over the string.
        for (int i = 0; i < s.size(); i++)
        {
            // While the stack is not empty and the top character of the stack is lexicographically larger than the current character,
            // and there are still occurrences of the top character left in the string, and the current character is not in the stack:
            while (!st.empty() && st.top() >= s[i] && freq[st.top() - 97] > 0 && taken[s[i] - 97] == false)
            {
                // Mark the top character of the stack as not taken and pop it from the stack.
                taken[st.top() - 97] = false;
                st.pop();
            }

            // If the current character is not in the stack:
            if (taken[s[i] - 97] == false)
            {
                // Push the current character onto the stack and mark it as taken.
                st.push(s[i]);
                taken[s[i] - 97] = true;
            }

            // Decrement the frequency of the current character.
            freq[s[i] - 97]--;
        }

        // Initialize an empty string for the answer.
        string ans = "";

        // While the stack is not empty:
        while (!st.empty())
        {
            // Add the top character of the stack to the front of 'ans' and pop it from the stack.
            ans = st.top() + ans;
            st.pop();
        }

        // Return 'ans'.
        return ans;
    }
};