// Write a program to find all the distinct triplets of an array that sum up to the given target 'K'
/*
Input : [0, 3, 1, 5, 4, 1, 2]    K = 6

Output : [0, 1, 5]  [0, 2, 4]  [1, 1, 4]  [1, 2, 3]
*/

// Using Two Pointer approach : TC = O(N^2)

#include <bits/stdc++.h>

// Function to find distinct triplets
vector<vector<int>> findTriplets(vector<int> arr, int n, int k)
{
    // Vector to store the result
    vector<vector<int>> ans;

    // Sorting the input array
    sort(arr.begin(), arr.end());

    // Loop through the array, excluding the last two elements
    for (int i = 0; i < n - 2; i++)
    {
        // Initializing the pointers s and e
        int s = i + 1;
        int e = n - 1;

        // Loop until s is less than e
        while (s < e)
        {
            // Calculate the sum of the current triplet
            int sum = arr[i] + arr[s] + arr[e];

            // If the sum is equal to k, add the triplet to the result vector
            if (sum == k)
            {
                ans.push_back({arr[i], arr[s], arr[e]});

                // Skip duplicate elements for pointers s and e
                while (s < e && arr[s] == arr[s + 1])
                    s++;
                while (s < e && arr[e] == arr[e - 1])
                    e--;

                // Move the pointers s and e
                s++;
                e--;
            }
            // If the sum is less than k, move pointer s to the right
            else if (sum < k)
            {
                s++;
            }
            // If the sum is greater than k, move pointer e to the left
            else if (sum > k)
            {
                e--;
            }
        }

        // Skip duplicate elements for pointer i
        while (i < n - 2 && arr[i] == arr[i + 1])
            i++;
    }

    // Return the result vector
    return ans;
}
