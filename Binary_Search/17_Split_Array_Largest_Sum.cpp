/*  https://leetcode.com/problems/split-array-largest-sum/description/

Exactly same as "Capacity to SHIP Packages"

410. Split Array Largest Sum
Hard

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest
sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
*/

class Solution
{
public:
    bool canSplit(vector<int> &nums, int k, int val)
    {
        int split = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] <= val)
            {
                sum += nums[i];
            }
            else
            {
                split++;
                sum = nums[i];
            }
        }
        return split <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int left = INT_MIN;
        int right = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            left = max(left, nums[i]);
            right += nums[i];
        }

        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, k, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};