// Write a program to return all the SUBSETS WITH SUM EQUAL TO 'K'.
/*
Input = 1, 2, 3, 4, 5, 6, 7, 8
TARGET = 8

Output:
1 2 5
1 3 4
1 7
2 6
3 5
8

*/

#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> nums, vector<vector<int>> &ans, vector<int> op, int target, int index)
{
    if (index == nums.size())
    {
        if (target == 0)
            ans.push_back(op);
        return;
    }

    op.push_back(nums[index]);
    helper(nums, ans, op, target - nums[index], index + 1);

    op.pop_back();
    helper(nums, ans, op, target, index + 1);
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