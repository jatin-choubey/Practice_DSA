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

We perform the Binary Search in order to get this element (4).

mid = 3
We see that, 2 < 3 < 4 . left goes on index 3

mid = 5
We see that, 4 > 2 > 1 . right goes on index 5

mid = 4
We see that, 3 < 4 > 2. Hence we found the peak. Return mid     Look Step 4
*/

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // Check if the middle element is the peak
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;

            // If the middle element is increasing, the peak lies on the right side
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
                left = mid; // Move the left pointer to mid + 1 to search in the right half

            // If the middle element is decreasing, the peak lies on the left side
            else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
                right = mid; // Move the right pointer to mid - 1 to search in the left half
        }

        return -1; // If no peak element is found, return -1
    }
};
