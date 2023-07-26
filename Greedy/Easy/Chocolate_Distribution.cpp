/*
Given an array A[ ] of positive integers of size N, where each value represents the number of
chocolates in a packet. Each packet can have a variable number of chocolates. There are M students,
the task is to distribute chocolate packets among M students such that :
1. Each student gets exactly one packet.
2. The difference between maximum number of chocolates given to a student and minimum number of
 chocolates given to a student is minimum.

Example :
Input: Number of students (m) = 5, Array = {3, 4, 1, 9, 56, 7, 9, 12}

Output: 6

Explanation: The minimum difference between maximum chocolates and minimum
chocolates is 9 - 3 = 6 by choosing following M packets :{3, 4, 9, 7, 9}.

*/

// The `findMinDiff` function calculates the minimum difference between the maximum and minimum number of chocolates
// distributed to `M` students from an array `a` of size `n`.

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long m)
    {
        long long n = a.size();

        // Sorting the input array in ascending order to find the minimum difference easily.
        sort(a.begin(), a.end());

        // Initializing two pointers `i` and `j` to form a sliding window of size `m`.
        long long i = 0;
        long long j = m - 1;

        // Initializing the `ans` variable to store the minimum difference between packets of chocolates.
        long long ans = INT_MAX;

        // Moving the sliding window through the array to calculate the minimum difference.
        while (j < n)
        {
            // Calculate the difference between the chocolates in the last and first packets of the window.
            long long diff = a[j] - a[i];

            // Update `ans` to store the minimum difference found so far.
            ans = min(ans, diff);

            // Move the window one position to the right by incrementing both `i` and `j`.
            i++;
            j++;
        }

        // Return the minimum difference between chocolates distributed to `M` students.
        return ans;
    }
};
