// LeetCode - 1870
// Link : https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/

/*
You are given a floating-point number hour, representing the amount of time you have to
reach the office. To commute to the office, you must take n trains in sequential order. You are also given an integer array dist of length n, where dist[i] describes the distance (in kilometers) of the ith train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours
before you can depart on the 2nd train ride at the 2 hour mark.
Return the minimum positive integer speed (in kilometers per hour) that all the trains must
travel at for you to reach the office on time, or -1 if it is impossible to be on time.

Tests are generated such that the answer will not exceed 107 and hour will have at most
two digits after the decimal point.
*/

// EXAMPLE
/*
Input: dist = [1,3,2], hour = 2.7
Output: 3
Explanation: At speed 3:
- The first train ride takes 1/3 = 0.33333 hours.
- Since we are not at an integer hour, we wait until the 1 hour mark to depart. The second train ride takes 3/3 = 1 hour.
- Since we are already at an integer hour, we depart immediately at the 2 hour mark. The third train takes 2/3 = 0.66667 hours.
- You will arrive at the 2.66667 hour mark.
*/

class Solution
{
public:
    int minSpeedOnTime(vector<int> &trainDistances, double targetHour)
    {
        int minSpeed = -1;                      // Variable to store the minimum required speed to be on time
        int lowSpeed = 1, highSpeed = 10000000; // Binary search range for speeds (1 to 10^7)

        while (lowSpeed <= highSpeed)
        {                                                             // Binary search loop
            int currentSpeed = lowSpeed + (highSpeed - lowSpeed) / 2; // Calculate the middle speed

            double totalTime = 0.0; // Variable to store the total time for the current speed

            // Calculate the total time required for each train ride based on the current speed
            for (int i = 0; i < trainDistances.size() - 1; ++i)
            {
                totalTime += ceil((double)trainDistances[i] / currentSpeed); // Add the time for each train ride and ceil the result
            }

            totalTime += (double)trainDistances.back() / currentSpeed; // Add the time for the last train ride (no waiting time)

            if (totalTime <= targetHour)
            {                                 // If the total time is less than or equal to the given target hour
                minSpeed = currentSpeed;      // Update the minimum required speed to the current speed
                highSpeed = currentSpeed - 1; // Continue searching for lower speeds
            }
            else
            {                                // If the total time is greater than the given target hour
                lowSpeed = currentSpeed + 1; // Continue searching for higher speeds
            }
        }

        return minSpeed; // Return the minimum required speed to reach the office on time, or -1 if it's not possible
    }
};
