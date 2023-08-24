// Write a program that prints the SUM of all the subets.
/*
EXAMPLE :
Input = 1, 2, 3

Output= []      = 0
        [1]     = 1
        [2]     = 2
        [3]     = 3
        [1,2]   = 3
        [1,3]   = 4
        [2,3]   = 5
        [1,2,3] = 6

OUTPUT : [0, 1, 2, 3, 3, 4, 5, 6]

*/

#include <bits/stdc++.h>

using namespace std;

void helper(vector<int> nums, vector<int> &ans, int sum, int index)
{
    if (index == nums.size())
    {
        ans.push_back(sum);
        return;
    }

    helper(nums, ans, sum + nums[index], index + 1);
    helper(nums, ans, sum, index + 1);
}
vector<int> subsetSum(vector<int> &nums)
{
    vector<int> ans;
    int sum = 0;
    helper(nums, ans, sum, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<int> ans = subsetSum(nums);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}