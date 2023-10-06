/*
Given an array of distinct integers nums and a target integer target, return a list of all
unique combinations of nums where the chosen numbers sum to target.
You may return the combinations in any order.

Input: nums = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]       -----> Note that we can incldue the same element more than once inorder to get the answer.

*/

class Solution
{
public:
    // Helper function to find combinations that sum up to the target
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> &op, int target, int index)
    {
        // Base case: If we have reached the end of the nums array
        if (index == nums.size())
        {
            // If the target is achieved, add the current combination (op) to the answer list (ans)
            if (target == 0)
            {
                ans.push_back(op);
            }
            return;
        }

        // Recursive case 1: Keep including the SAME (Index) Element till it is not greater than the target value.
        if (nums[index] <= target)
        {
            op.push_back(nums[index]); // Add the current element to the combination (op)
            // Recur with the reduced target (target - nums[index]) and the same index, as the element can be used again
            helper(nums, ans, op, target - nums[index], index);
            op.pop_back(); // Backtrack by removing the last element, as we need to explore other combinations
        }

        // Recursive case 2: Exclude the current element (nums[index]) from the combination
        // Move on to the next index to explore other elements in the nums array
        helper(nums, ans, op, target, index + 1);
    }

    // Main function to find all combinations that sum up to the target
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<int> op;                       // Store the current combination
        vector<vector<int>> ans;              // Store the final list of combinations
        int index = 0;                        // Start with the first element (index 0) of the nums array
        helper(nums, ans, op, target, index); // Call the helper function to find combinations
        return ans;                           // Return the answer list containing all combinations
    }
};
