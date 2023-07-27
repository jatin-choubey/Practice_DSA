// LeetCode - 162
// Link : https://leetcode.com/problems/find-peak-element/description/

// APPROACH 1
class Solution
{
public:
    // Helper function to find a peak element in the given range [s, e]
    int helper(vector<int> &nums, int s, int e)
    {
        // Calculate the middle index
        int m = (s + e) / 2;

        // Check if the middle element is a peak element
        if (m > s && m < e && nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
        {
            cout << "Found peak " << nums[m] << " at index " << m << endl;
            return m;
        }

        // Check if the first or last element is a peak element
        if (m == s && m + 1 < nums.size() && nums[m] > nums[m + 1])
        {
            return m;
        }
        else if (m == e && m - 1 >= 0 && nums[m] > nums[m - 1])
        {
            return m;
        }

        // Recursively search for a peak element on the left side
        if (m > s && nums[m] < nums[m - 1])
        {
            return helper(nums, s, m - 1);
        }

        // Recursively search for a peak element on the right side
        if (m < e && nums[m] < nums[m + 1])
        {
            return helper(nums, m + 1, e);
        }

        // If nums[m] is a local maximum, we can return m as a peak element
        return m;
    }

    // Main function to find a peak element in the given array
    int findPeakElement(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }
};

// Approach 2
/*
Another approach is to find the middle element and see if the element to its left is bigger or the right is bigger.
If the peak on the left is bigger, means we need to search in left subarray else right sub array
*/