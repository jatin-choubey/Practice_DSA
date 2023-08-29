/*  https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
1011. Capacity To Ship Packages Within D Days

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with
packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.



Example 1 ------
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15

Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

Example 2 ---------
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6

Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
*/

class Solution
{
public:
    // Function to check if we can Ship all the packages within the given 'days' if we consider the ship's capacity as 'shipCapacity' which is basically the 'mid' value.
    bool canShip(vector<int> &weights, int days, int shipCapacity)
    {
        int sum = weights[0]; // Initialize the sum with the first package's weight
        int requiredDays = 1; // Initialize the number of days required to ship all the packages

        // Iterate over all the package weights
        for (int i = 1; i < weights.size(); i++)
        {
            if (sum + weights[i] <= shipCapacity)
            {
                sum += weights[i]; // Add the weight to the current sum if it doesn't exceed the ship's capacity
            }
            else
            {
                requiredDays++; // Increment the required days if the weight exceeds the ship's capacity
                sum = 0;
                sum = weights[i]; // Reset the sum for the new batch of packages
            }
        }

        return requiredDays <= days; // Return true if the required days are less than or equal to the given 'days'
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = INT_MIN; // Initialize the minimum left boundary for binary search
        int right = 0;      // Initialize the maximum right boundary for binary search

        // Find the maximum package weight and sum of all package weights
        for (int i = 0; i < weights.size(); i++)
        {
            left = max(weights[i], left); // Minimum possible weight that we can ship in a single day is maximum weight of all the weights.
            right += weights[i];          // Maximum weight that we can transefer in a single day is sum of all the weights.
        }

        int ans = -1; // Initialize the answer variable

        // Perform binary search to find the minimum capacity that meets the criteria
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // Calculate the mid-point capacity

            if (canShip(weights, days, mid))
            {
                ans = mid;       // Update the answer if the current capacity can ship packages in the given days
                right = mid - 1; // Adjust the right boundary for lower capacities
            }
            else
            {
                left = mid + 1; // Adjust the left boundary for higher capacities
            }
        }

        return ans; // Return the minimum capacity that can ship packages in the given days
    }
};
