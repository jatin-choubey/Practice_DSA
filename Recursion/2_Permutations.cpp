// Write a program to print all the permutations of a number
/*
EXAMPLE --
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
class Solution
{
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, int index)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            helper(nums, ans, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        helper(nums, ans, 0);
        return ans;
    }
};