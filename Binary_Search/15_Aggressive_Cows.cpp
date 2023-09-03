/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer
'k' which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the
minimum distance between any two of them is the maximum possible.

Example 1:

Input:
n=5
k=3
stalls = [1 2 4 8 9]
Output:
3
*/

class Solution
{
public:
    // This function checks if we can place 'k' cows with a minimum distance 'val' between them.
    bool canWePlace(vector<int> &stalls, int val, int k)
    {
        int count = 1;        // Initialize the count of cows to 1, assuming the first stall is always occupied.
        int last = stalls[0]; // Initialize the last occupied stall as the first one.

        // Iterate through the stalls starting from the second stall (index 1).
        for (int i = 1; i < stalls.size(); i++)
        {
            // Check if the current stall can accommodate a cow with the minimum distance 'val'.

            // The key idea here is that we are trying to maximize the minimum distance
            // between cows. If 'last + val' is less than or equal to 'stalls[i]', it means
            // we can place a cow at 'stalls[i]' while maintaining the minimum distance 'val'.
            if (last + val <= stalls[i])
            {
                count++;          // If yes, increment the count of cows.
                last = stalls[i]; // Update the last occupied stall to the current one.
            }
        }

        // After iterating through all the stalls, we check if we were able to place 'k' or more cows
        // with the minimum distance 'val' between them. If 'count' is greater than or equal to 'k',
        // it means it's possible to place 'k' cows with this minimum distance.
        return count >= k; // Return true if it's possible, false otherwise.
    }

    int solve(int n, int k, vector<int> &stalls)
    {
        sort(stalls.begin(), stalls.end()); // Sort the stalls in ascending order.

        int left = 1;                                      // Initialize the left boundary for binary search.
        int right = stalls[stalls.size() - 1] - stalls[0]; // Initialize the right boundary.

        int ans = 0; // Initialize the answer to 0.

        while (left <= right)
        {
            int mid = left + (right - left) / 2; // Calculate the middle value of the boundaries.

            if (canWePlace(stalls, mid, k))
            {
                ans = mid;      // Update the answer if it's possible to place 'k' cows with minimum distance 'mid'.
                left = mid + 1; // Move the left boundary to the right.
            }
            else
            {
                right = mid - 1; // If not possible, move the right boundary to the left.
            }
        }

        return ans; // Return the final answer.
    }
};
