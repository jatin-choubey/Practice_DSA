// Search for an element in the Rotated Sorted Array
/*
Input : 6 7 8 9 1 2 3 4 5   Key = 8
Output : Found at Index 2


*/
// Function to search for an element 'key' in a rotated sorted array 'arr' of size 'n'
int search(vector<int> &arr, int n, int key)
{
    // Initialize the left and right pointers for binary search
    int left = 0;
    int right = arr.size() - 1;

    // Perform binary search until the left pointer crosses the right pointer
    while (left <= right)
    {
        // Calculate the middle index
        int mid = (left + right) / 2;

        // If the middle element is equal to the target 'key', return its index
        if (arr[mid] == key)
            return mid;

        // Checking if the RIGHT HALF of the array is SORTED
        if (arr[mid] < arr[right])
        {
            /* If the target 'key' is greater than the middle element and less than or equal
            to the rightmost element, search in the right half; otherwise, search in the left half
            */
            if (key > arr[mid] && key <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        // ELse LEFT HALF of array will be SORTED for sure.
        else
        {
            /* If the target 'key' is greater than or equal to the leftmost element and less than
            the middle element, earch in the left half; otherwise, search in the right half.
            */
            if (key >= arr[left] && key < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }

    // If the target 'key' is not found in the array, return -1
    return -1;
}
