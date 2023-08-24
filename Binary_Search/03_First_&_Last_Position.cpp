/*
Find First and Last Position of Element in Sorted Array.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

// Approach 1  ->  Using the inbuilt STL Functions for lower and upper bound.
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(nums.begin(), nums.end(), target);

        int lb = distance(nums.begin(), lower); // Get the exact index of Lower Bound
        int ub = distance(nums.begin(), upper); // Get the exact index of Upper Bound

        if (lb == nums.size() || nums[lb] == target) // If the lower bound is at last index or the lower bound DOES NOT POINT AT EXACT INDEX
            return {-1, -1};                         // Means the element not found in the sorted array and hence return -1, -1

        return {lb, ub - 1}; // Else return the lower bound and upper bound - 1 (ub - 1 because the upper bound points to the index onr above the last occurence of target)
    }
};

// Approach 2 -> Full Binary Search for First and Last occourence
class Solution
{
public:
    int lowerBound(vector<int> &nums, int left, int right, int target)
    {
        int ans = -1;
        while (left <= right) // Change condition to include the equal case
        {
            int mid = left + (right - left) / 2; // Use this to prevent potential integer overflow
            if (nums[mid] == target)
            {
                ans = mid; // If the number is found, store it as the current ans and search in the left subarray for smaller index.
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> &nums, int left, int right, int target)
    {
        int ans = -1;
        while (left <= right) // Change condition to include the equal case
        {
            int mid = left + (right - left) / 2; // Use this to prevent potential integer overflow
            if (nums[mid] == target)
            {
                ans = mid;
                left = mid + 1; // If the number is found, store it as the current ans and search in the right subarray for bigger index.
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {

        int l = lowerBound(nums, 0, nums.size() - 1, target);
        int u = upperBound(nums, 0, nums.size() - 1, target);
        return {l, u};
    }
};
