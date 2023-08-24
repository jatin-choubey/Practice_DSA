/*
Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0;                // Initialize the left pointer to the beginning of the array.
        int right = nums.size() - 1; // Initialize the right pointer to the end of the array.

        while (left < right)
        {
            int mid = (left + right) / 2; // Calculate the middle index between left and right.

            // Check if the middle index is even and the value at mid is the same as the next element,
            // OR if the middle index is odd and the value at mid is the same as the previous element.
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            {
                left = mid + 1; // Move the left pointer to the next index, as the single element must be on the right side.
            }
            else
            {
                right = mid; // Move the right pointer to the middle index, as the single element must be on the left side or at mid.
            }
        }
        return nums[left]; // Return the value at the final left pointer position, which points to the single element.
    }
};
