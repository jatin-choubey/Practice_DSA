/*  https://leetcode.com/problems/kth-missing-positive-number/description/
1539. Kth Missing Positive Number
Easy

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.



Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.


Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

*/

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        // Initialize two pointers, 'left' and 'right', to define a range.
        int left = 0, right = arr.size() - 1;

        // Use a binary search to find the Kth missing positive number.
        while (left <= right)
        {
            // Calculate the middle index of the current range.
            int mid = left + (right - left) / 2;

            // Calculate the actual position (index) of arr[mid] where it should have been
            // if there were no missing numbers before it. We subtract 1 because array indexing starts from 0.
            int actual = arr[mid] - 1;

            // Calculate the difference between the actual missing number and 'mid'.
            int diff = actual - mid;

            // If the difference is less than 'k', it means there are fewer missing numbers
            // in the left half of the range, so we update 'left' to narrow the search.
            if (diff < k)
            {
                left = mid + 1;
            }
            else
            {
                // If the difference is greater than or equal to 'k', it means there are
                // at least 'k' missing numbers in the left half, so we update 'right' to
                // narrow the search in that direction.
                right = mid - 1;
            }
        }

        // The final result is calculated by adding 'k' to 'right' and then adding 1.
        // This is because 'right' points to the last missing number before reaching 'k'.
        return k + right + 1;
    }
};
