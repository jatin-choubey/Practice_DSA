/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array
to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

// Approach 1 (Brute Force)     TC = O(n^2)
// Find out the sum maximum of every window and store them in answer vector.

// Apprach 2 (Decreasing Order Dequeu)
// Maintaining a decreasing order Deque, because this will ensure that the front of dequeue will always be containing the largest element among 'K' elements.
// example -> 4 3 -1
// Maintain a decreasing order deque using the monotonic property of the doubly ended queue from the back
// And also remove the elements from the front if the elements in the dequeue exceed the given 'K'
// TC = O(n)          WHY ??
// Here's why. Because despite having a while loop inside the for loop, every element is added and removed exactly one time.

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // Initialize a double-ended queue and a vector to store the maximum values
        deque<int> dq;
        vector<int> ans;

        // Process the first 'k' elements in the array
        for (int i = 0; i < k; i++)
        {
            // For each element, remove the elements from the back of the queue which are less than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            // Add the index of the current element to the back of the queue
            dq.push_back(i);
        }

        // The front of the queue is the index of maximum element in the first 'k' elements, add it to 'ans'
        ans.push_back(nums[dq.front()]);

        // Process rest of the elements in array
        for (int i = k; i < nums.size(); i++)
        {
            // Remove elements from front of queue if they are out of current window
            while (!dq.empty() && i - dq.front() > k - 1)
                dq.pop_front();

            // Similar to above, remove elements from back which are less than current element
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            // Add index of current element to back of queue
            dq.push_back(i);

            // Front of queue has maximum element in current window, add it to 'ans'
            ans.push_back(nums[dq.front()]);
        }

        // Return vector 'ans' containing maximums of all windows
        return ans;
    }
};
