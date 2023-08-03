// Write a program to return ONLY ONE of the subsets with SUM EQUAL TO 'K'.
/*
Input = 1, 2, 3, 4, 5, 6, 7, 8
TARGET = 8

Output:
1 2 5

*/

#include <bits/stdc++.h>
using namespace std;
bool helper(vector<int> nums, vector<vector<int>> &ans, vector<int> op, int target, int index)
{
    if (index == nums.size())
    {
        if (target == 0)
        {
            ans.push_back(op);
            return true; // FOUND. Return True.
        }
        return false; // NOT. Return False
    }

    op.push_back(nums[index]);
    if (helper(nums, ans, op, target - nums[index], index + 1) == true)
        return true;

    op.pop_back();
    if (helper(nums, ans, op, target, index + 1) == true)
        return true;

    return false;
}
vector<vector<int>> subSetK(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    vector<int> op;
    helper(nums, ans, op, target, 0);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<vector<int>> ans = subSetK(nums, 8);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}