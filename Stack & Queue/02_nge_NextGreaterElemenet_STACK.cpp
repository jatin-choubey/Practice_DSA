#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> nge; // Stack to store indices

    for (int i = 0; i < n; i++)
    {
        while (!nge.empty() && nums[i] > nums[nge.top()])
        {
            result[nge.top()] = nums[i];
            nge.pop();
        }
        nge.push(i);
    }

    return result;
}

int main()
{
    vector<int> nums = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    vector<int> ans = nextGreater(nums);

    for (auto i : ans)
        cout << i << " ";

    return 0;
}
