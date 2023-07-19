// Write a program to calcualte the water trapped between pillars.

//    4 |                     __
//    3 |         __         |  |__    __
//    2 |   __   |  |__    __|  |  |__|  |__
//    1 |  |  |  |  |  |  |  |  |  |  |  |  |
//    0 |*************************************
//       0  1  2  3  4  5  6  7  8  9  10  11
// The water will get logged at indexs 2, 4, 5, 6, 9

// Approach 1 : Brute Force : TC = O(n^2)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int water = 0;

        for (int i = 1; i < n - 1; i++) // Iterate for every element
        {
            int leftMax = 0;
            int rightMax = 0;

            // Find the maximum height on the left of the current bar
            for (int j = i - 1; j >= 0; j--)
            {
                leftMax = max(leftMax, height[j]);
            }

            // Find the maximum height on the right of the current bar
            for (int j = i + 1; j < n; j++)
            {
                rightMax = max(rightMax, height[j]);
            }

            // Calculate the trapped water for the current bar
            int minHeight = min(leftMax, rightMax);
            if (minHeight > height[i])
            {
                water += minHeight - height[i];
            }
        }

        return water;
    }
};

// Approach 2 : Using Prefix and Suffix sum
// TC : O(3N), which is approximately equal to O(N)
// SC : O(2N), Using two external vectors to store prefix and suffix

// Consider the below given list for better understanding of the code.
// Index:      0  1  2  3  4  5  6  7  8  9 10 11 (Bars)
// Height:     0  1  0  2  1  0  1  3  2  1  2  1

// LeftMax:    0  1  1  2  2  2  2  3  3  3  3  3
// RightMax:   3  3  3  3  3  3  3  3  2  2  2  1

// MinHeight:  0  1  1  2  2  2  2  3  2  2  2  1

// Water:      0  0  1  0  1  2  1  0  0  1  0  0

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int water = 0;

        vector<int> leftMax(n);  // Prefix sum to store maximum height on the left of each bar
        vector<int> rightMax(n); // Suffix sum to store maximum height on the right of each bar

        // Initialize the first and last elements of leftMax and rightMax
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        // Compute the maximum heights on the left of each bar
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Compute the maximum heights on the right of each bar
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate the trapped water for each bar
        for (int i = 1; i < n - 1; i++)
        {
            int minHeight = min(leftMax[i], rightMax[i]);
            if (minHeight > height[i])
            {
                water += minHeight - height[i];
            }
        }

        return water;
    }
};

// Approach 3 : Optimal Solution (Two Pointers)

// Function to calculate the trapped rainwater in an array of heights
int getTrappedWater(int *arr, int n)
{
    // Initialize two pointers for the left and right ends of the array
    int l = 0;     // Pointer for the left end of the array
    int r = n - 1; // Pointer for the right end of the array

    // Initialize variables to store the maximum height encountered from the left and right
    int lmax = 0; // Maximum height from the left side
    int rmax = 0; // Maximum height from the right side

    int water = 0; // Variable to store the total trapped water

    // Loop until the two pointers meet or cross each other
    while (l <= r)
    {
        // If the height at the left pointer is less than or equal to the height at the right pointer
        if (arr[l] <= arr[r])
        {
            // Check if the height at the left pointer is greater than the left maximum height
            if (arr[l] > lmax)
                lmax = arr[l]; // Update the left maximum height

            // Calculate the trapped water at the current position and add it to the total
            // The trapped water is the difference between the left maximum height and the height at the current position
            // If the height at the current position is greater than the left maximum height, then no water can be trapped at this position
            // Otherwise, the trapped water will be the difference between the two heights
            else
                water += lmax - arr[l];

            // Move the left pointer to the right
            l++;
        }
        // If the height at the right pointer is less than the height at the left pointer
        else
        {
            // Check if the height at the right pointer is greater than the right maximum height
            if (arr[r] > rmax)
                rmax = arr[r]; // Update the right maximum height

            // Calculate the trapped water at the current position and add it to the total
            // The trapped water is the difference between the right maximum height and the height at the current position
            // If the height at the current position is greater than the right maximum height, then no water can be trapped at this position
            // Otherwise, the trapped water will be the difference between the two heights
            else
                water += rmax - arr[r];

            // Move the right pointer to the left
            r--;
        }
    }

    // Return the total trapped water
    return water;
}
