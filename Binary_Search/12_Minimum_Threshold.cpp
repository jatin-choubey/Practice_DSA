/* https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
1283. Find the Smallest Divisor Given a Threshold

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result.
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.



Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
*/

class Solution
{
public:
    // This function calculates the sum of division results using a given divisor value
    int calculate(vector<int> &nums, int val)
    {
        // Initialize a variable to keep track of the sum of rounded division results
        double sum = 0;

        // Iterate through each element in the nums array
        for (int i = 0; i < nums.size(); i++)
        {
            // Convert the current element to a double and divide it by the divisor
            double x = (double)nums[i] / val;

            // Round up the division result to the nearest integer using the ceil() function
            x = ceil(x);

            // Add the rounded-up division result to the sum
            sum += x;
        }

        // Return the sum as an integer
        return (int)sum;
    }

    // This function finds the smallest divisor that results in a sum of division results within the given threshold
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        // Initialize the left and right pointers for the binary search
        int left = 1;
        int right = INT_MIN; // Initialize right to a very small value

        // Find the maximum element in the nums array to set a suitable upper bound for the binary search
        for (int i = 0; i < nums.size(); i++)
        {
            right = max(right, nums[i]);
        }

        int ans = -1; // Initialize the answer to an invalid value

        // Perform binary search until the left and right pointers meet
        while (left <= right)
        {
            // Calculate the middle value between left and right
            int mid = left + (right - left) / 2;

            // Calculate the sum of division results using the current middle value
            int value = calculate(nums, mid);

            // Check if the calculated sum of division results is within the given threshold
            if (value <= threshold)
            {
                // If the sum is within the threshold, update the answer and search for a smaller divisor
                ans = mid;
                right = mid - 1;
            }
            else
            {
                // If the sum exceeds the threshold, search for a larger divisor on the right side
                left = mid + 1;
            }
        }

        // Return the smallest divisor that results in a sum within the threshold
        return ans;
    }
};
