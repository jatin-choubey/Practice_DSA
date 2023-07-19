// Write a program to Remove Duplicates from Sorted Array.
/*
input : 1 1 2 3 3 3 3 4 4 5
after removing duplicattes : 1 2 3 4 5 _ _ _ _ _
output = 5

*/

// Approach 1 : Use Set Data Structure

// Approach 2 (2 pointers)

int removeDuplicates(vector<int> &nums, int n)
{
    int s = 0; // Pointer to keep track of the current position to replace the duplicates
    int e = 1; // Pointer to traverse the vector and find duplicates

    // Continue the loop until the end pointer (e) reaches the end of the vector
    while (e < n)
    {
        // If the element at the start pointer (s) is different from the element at the end pointer (e),
        // it means the end pointer (e) has found a new distinct element
        if (nums[s] != nums[e])
        {
            s++;               // Move the start pointer (s) one step forward to the next position to replace the duplicates
            nums[s] = nums[e]; // Replace the element at the start pointer (s) with the new distinct element found at the end pointer (e)
        }
        e++; // Move the end pointer (e) one step forward to check the next element in the vector
    }

    // The value of s at this point will be the index of the last distinct element in the vector,
    // so the new length of the vector (after removing duplicates) is s + 1.
    return s + 1;
}
