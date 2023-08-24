/*
Find the Smallest Element in the Rotated Sorted Array
INPUT : 6 7 1 2 3 4 5
OUTPUT : 1

*/

// -------------------------- APPROACH 1 ---------------------------------

int findMin(const std::vector<int> &nums)
{
    int left = 0;                // Initialize left pointer at the start of the array
    int right = nums.size() - 1; // Initialize right pointer at the end of the array

    while (left < right)
    {                                        // Binary search loop continues until left and right pointers meet
        int mid = left + (right - left) / 2; // Calculate mid index to split the search range

        // Check if the value at the middle index is greater than the value at the right index.
        // This comparison is crucial for detecting the pivot point where the smallest element is located.
        if (nums[mid] > nums[right])
        {
            // If true, it means the pivot point is somewhere between mid and right.
            // Therefore, we can safely move the left pointer to mid + 1 and continue searching in the right subarray.
            left = mid + 1;
        }
        else
        {
            // If false, it means the pivot point is somewhere to the left of mid or coincides with mid.
            // In this case, we move the right pointer to mid, effectively narrowing down the search to the left subarray.
            right = mid;
        }
    }

    // At this point, the left and right pointers have converged, and we have found the minimum element.
    // We return the value at the 'left' index, which holds the minimum element.
    return nums[left];
}

// ------------------------------- APPROACH 2 ----------------------------------

int findMin(vector<int> &arr)
{
    int ans = INT_MAX;         // Initialize ans to a large value
    int low = 0;               // Initialize low pointer
    int high = arr.size() - 1; // Initialize high pointer

    while (low <= high)
    {                               // Binary search loop
        int mid = (low + high) / 2; // Calculate mid index

        if (arr[low] <= arr[mid])
        {                             // If left part is sorted
            ans = min(ans, arr[low]); // Update ans with minimum of ans and arr[low]
            low = mid + 1;            // Move low pointer to mid + 1
        }
        else
        {                             // If right part is sorted (including mid)
            ans = min(ans, arr[mid]); // Update ans with minimum of ans and arr[mid]
            high = mid;               // Move high pointer to mid
        }
    }
    return ans; // Return the minimum element found
}
