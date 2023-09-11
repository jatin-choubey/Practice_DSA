#include <bits/stdc++.h>
using namespace std;
void maxHeap(vector<int> &nums, int i)
{
    int left = 2 * i + 1;  // Find the index for the left child of the current index.
    int right = 2 * i + 2; // Find the index for the Right child of the current index.
    int largest;

    if (left <= nums.size() - 1 && nums[left] > nums[i] && nums[left] > nums[right])        // If left child is greater than Root (i) and the Right child as well.
        largest = left;                                                                     // Mark the left child as the largest
    else if (right <= nums.size() - 1 && nums[right] > nums[i] && nums[right] > nums[left]) // If the Right Child is greater than Root (i) and the Left child as well
        largest = right;                                                                    // Mark the right child as the largest.
    else
        largest = i; // Else the Root (i) is greater than both its children

    // If the largest found so far is not the Root (i), we swap the root with the largest element.
    if (largest != i)
    {
        swap(nums[largest], nums[i]);
        maxHeap(nums, largest);
    }
}
int main()
{
    vector<int> nums = {1, 7, 5, 8, 6, 4, 3};
    int n = nums.size();

    // Max heapify all the Sub trees from bottom to the top one by one.
    // NOTE:  Non-Leaf Nodes are nodes from index 0 to (n/2)-1
    for (int i = (n / 2) - 1; i >= 0; i--)
        maxHeap(nums, i);

    for (auto element : nums)
        cout << element << " ";

    return 0;
}