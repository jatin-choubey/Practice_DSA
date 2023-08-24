/*
Given an array of numbers (nums) and a target number (target),
Find all unique combinations in 'nums' where the elements sum to target.

Each number in the 'nums' array may only be used once in the combination.

Input: nums = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Approach:

1. Sort the input array.
    RECURSIVE FUNCTION
2. If the target becomes zero, answer found, store in answer vector.
3. Run an iteration from every element till the last element

    ie. Iterate from 0 to 3
        Iterate from 1 to 3
        Iterate from 2 to 3
        Iterate from 3 to 3

4. If the element becomes greater than target, we are sure that we will not be able to add any further elements,
    as the input array is in sorted order.

5. If the current element was equal to the previous element, WE SKIP, as we dont want to pick the repeated numbers.

6. Push element in vector.

7. Recursive Call.

8. BackTrack POP_BACK.

*/

class Solution
{
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> &op, int target, int index)
    {
        // If target reaches 0, we found our ans.
        if (target == 0)
        {
            ans.push_back(op);
            return;
        }

        // The FOR LOOP will start making the subsequence from every element of the input array.
        for (int i = index; i < nums.size(); i++)
        {
            // if the element is greater than target, we are sure of not finding possible answers any further (As the array is sorted)
            if (nums[i] > target)
                break;

            // Skip if the elements are same
            if (i > index && nums[i] == nums[i - 1])
                continue;

            // Push the element in the vector.
            op.push_back(nums[i]);                          // Store the element in the vector.
            helper(nums, ans, op, target - nums[i], i + 1); // Recursion
            op.pop_back();                                  // Backtracking
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> op;
        helper(nums, ans, op, target, 0);
        return ans;
    }
};