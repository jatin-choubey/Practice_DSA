/*  https://leetcode.com/problems/minimum-replacements-to-sort-the-array/description/
2366. Minimum Replacements to Sort the Array
Hard

You are given a 0-indexed integer array nums. In one operation you can replace any element of the array
with any two elements that sum to it.

For example, consider nums = [5,6,7]. In one operation, we can replace nums[1] with 2 and 4 and convert nums to [5,2,4,7].
Return the minimum number of operations to make an array that is sorted in non-decreasing order.



---------- Example 1 ------------

Input: nums = [3,9,3]
Output: 2
Explanation: Here are the steps to sort the array in non-decreasing order:
- From [3,9,3], replace the 9 with 3 and 6 so the array becomes [3,3,6,3]
- From [3,3,6,3], replace the 6 with 3 and 3 so the array becomes [3,3,3,3,3]
There are 2 steps to sort the array in non-decreasing order. Therefore, we return 2.



---------- Example 2: -------------

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: The array is already in non-decreasing order. Therefore, we return 0.
*/

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {

        // Initialize the answer to be 0
        long long ans = 0;

        // Initialize the upper bound to be the last element of the array
        long long upperBound = nums[nums.size() - 1];

        // Iterate from the second last element to the first element
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // Calculate the number of partitions needed to make the current element smaller than or equal to the upper bound
            int partition = ceil((double)nums[i] / upperBound);

            // Add the number of operations needed to make the current element smaller than or equal to the upper bound
            ans += partition - 1;

            // Update the upper bound to be the largest possible value that is smaller than or equal to the current element after partitioning
            upperBound = floor((double)nums[i] / partition);
        }

        // Return the final answer
        return ans;
    }
};
