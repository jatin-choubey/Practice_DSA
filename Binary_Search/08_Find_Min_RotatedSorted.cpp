// Find the Smallest element in the rotated sorted array. But array may contain Duplicates.
/*
Example 1:
-----------
Input: nums = [1,3,5]
Output: 1

Example 2:
-----------
Input: nums = [2,2,2,0,1]
Output: 0

Example 3:
-----------
Input : [2,2,2,0,2,2]
Outout: 0

*/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1; // Initialize two pointers, left and right, to the start and end of the array.

        while (left < right)
        {                                 // Enter a loop that continues as long as left pointer is less than the right pointer.
            int mid = (left + right) / 2; // Calculate the middle index between left and right pointers.

            if (nums[mid] > nums[right]) // Check if the value at middle index is greater than the value at right pointer.
            {
                left = mid + 1; // If true, Pivot is somewhere between Mid and Right.
            }

            else if (nums[mid] < nums[right]) // Check if the value at middle index is less than the value at right pointer.
            {
                right = mid; // If True, Pivot if between Mid and left, both inclusive.
            }
            else
                right--; // If the values at middle and right are equal, decrement the right pointer to consider the next element.

            // This handles the situation where there are duplicate elements. It helps us narrow down the search space.
        }

        return nums[right]; // When the loop ends (left >= right), the right pointer points to the minimum element.
    }
};
