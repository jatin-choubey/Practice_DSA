// LeetCode - 2141
// Link : https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

/*
QUESTION:

You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can
run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment,
you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be
a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.



INTUITION :
- The problem is to find the maximum running time of n computers using the given batteries,
  such that all computers run simultaneously and batteries can be swapped between computers at any time.

- The key observation is that the maximum running time of all computers is limited by the minimum running time of any computer.
  In other words, if we can run a computer for x minutes, then we can run all n computers for x minutes by swapping batteries as needed.

- Therefore, the problem becomes finding the maximum value of x such that we can run all n computers for 'x' minutes using
  the given batteries. This is equivalent to finding the maximum value of x such that the total running time of all batteries is at least x * n minutes.

- To find this value of 'x', we can use binary search on the range [0, atMax], where atMax is the sum of all battery times divided by n.

- For each value of 'x' in the binary search, we calculate the total running time of all batteries if we
  use them optimally, i.e., we use each battery for at most 'x' minutes or until it runs out.

- If the total running time is at least x * n minutes, then we update our answer to 'x' and continue searching
  in the right half of the range.
  Otherwise, we search in the left half of the range.

*/

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long sum = 0;
        for (auto i : batteries)
            sum += i;

        // Calculate the maximum possible running time of any computer, which is equal to the sum of all battery times divided by n
        long long atMax = sum / n;

        // Initialize variables to store the start and end points of the binary search range, which are 0 and atMax respectively
        long long s = 0;
        long long e = atMax;
        // Initialize a variable to store the answer, which is the maximum running time of n computers
        long long ans = 0;
        // Loop until the start point is greater than the end point
        while (s <= e)
        {
            // Calculate the middle point of the range, which is the candidate value for the maximum running time
            long long mid = (s + e) / 2;

            // Initialize a variable to store the total running time of all batteries if we use them optimally, i.e., we use each battery for at most mid minutes or until it runs out
            long long totalTime = 0;
            // Loop through the batteries array and add min(mid, i) to the total running time, where i is the battery time
            for (auto i : batteries)
                totalTime += min(mid, (long long)i);

            // Check if the total running time is at least mid * n minutes, which means we can run all n computers for mid minutes using the given batteries
            if (totalTime >= mid * n)
            {
                // Update the answer to mid and continue searching in the right half of the range
                ans = mid;
                s = mid + 1;
            }
            else
            {
                // Otherwise, search in the left half of the range
                e = mid - 1;
            }
        }
        // Return the answer as the maximum running time of n computers
        return ans;
    }
};