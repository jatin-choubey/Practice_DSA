/*
Given an integer array nums of unique elements, return all possible
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

// APPROACH : INCLUDE , EXCLUDE

class Solution
{
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> op, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(op);
            return;
        }
        // include
        op.push_back(nums[index]); // Including element
        helper(nums, ans, op, index + 1);

        // exclude
        op.pop_back(); // Backtrack (Excluding the included element)
        helper(nums, ans, op, index + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> op;
        helper(nums, ans, op, 0);
        return ans;
    }
};
