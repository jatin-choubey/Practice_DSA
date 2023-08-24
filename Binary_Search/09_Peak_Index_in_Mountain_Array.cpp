// LeetCode - 852
// Link : https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
/*
An array arr a mountain if the following properties hold:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

You must solve it in O(log(arr.length)) time complexity.
*/

//  EXAMPLE
/*
Index : 0 1 2 3 4 5 6 7
Array : 0 1 2 3 4 2 1 0
From the above given example, we see that 4 is the peak of the mountian whose both left and right neighbours are smaller than it.



                X
            X   X
        X   X   X   X
.   X   X   X   X   X   X   .
```````````````````````````````
0   1   2   3   4   2   1   0


We perform the Binary Search in order to get this element (4).

mid = 3
We see that, 2 < 3 < 4 . left goes on index 3

mid = 5
We see that, 4 > 2 > 1 . right goes on index 5

mid = 4
We see that, 3 < 4 > 2. Hence we found the peak. Return mid     Look Step 4
*/
// This function finds the peak element in a mountain array, where elements increase and then decrease.

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();

    // If there's only one element, it's the peak.
    if (n == 1)
        return 0;

    // By doing the Below two Conditional checks, we make sure that we dont get stuck in the edge case were Peak is first or last element.
    // Because if the Peak is last or first element, we will be checking peak with elements out of bounds, resulting in error.

    // Check if the first element is greater than the second. If yes, it's the peak.
    if (nums[0] > nums[1])
        return 0;

    // Check if the last element is greater than the second-to-last. If yes, it's the peak.
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    // Now, we perform binary search to find the peak element.
    int left = 1, right = n - 2;

    while (left <= right)
    {
        // Calculate the middle index of the current search range.
        int mid = (left + right) / 2;

        // Check if the current mid element is greater than its neighbors, which indicates a peak.
        if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
            return mid;

        // If the mid element is smaller than its next element but larger than the previous element,
        // then the peak must be on the right side. Move the left pointer to mid + 1.
        else if (nums[mid] < nums[mid + 1] && nums[mid] > nums[mid - 1])
            left = mid + 1;

        // Otherwise, the peak must be on the left side. Move the right pointer to mid - 1.
        else
            right = mid - 1;
    }

    // Return -1 to indicate that no peak was found (although this condition should not occur in a valid mountain array).
    return -1;
}
