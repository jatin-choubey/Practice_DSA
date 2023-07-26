/*
There are given N ropes of different lengths, we need to connect these ropes into one rope.
The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.

EXAMPLE:
Input: n = 5, arr[] = {4, 2, 7, 6, 9}

Output: 62

Explanation:

First, connect ropes 4 and 2.
Which makes the array {6,7,6,9}.
Cost of this operation 4+2 = 6.

Next, add ropes 6 and 6.
Which results in {12,7,9}.
Cost of this operation 6+6 = 12.

Then, add 7 and 9.
Which makes the array {12,16}.
Cost of this operation 7+9 = 16.

And finally, add 12 and 16 two which gives {28}.
Hence, the total cost is 6 + 12 + 16 + 28 = 62.
*/

// USING PRIORITY QUEUE
// The `minCost` function calculates the minimum cost of connecting N ropes of different lengths into one rope.
// The cost to connect two ropes is equal to the sum of their lengths.

class Solution
{
public:
    // CustomComparator is a struct that defines a custom comparison function for the priority_queue.
    struct CustomComparator
    {
        // The custom comparison function for the priority_queue.
        // It returns true if 'a' should appear after 'b' in the priority_queue.
        bool operator()(const long long &a, const long long &b) const
        {
            return a > b; // Using greater than operator to get a min-heap behavior.
        }
    };

    // Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {

        // Create a priority_queue with a custom comparator to get a min-heap behavior.
        // The priority_queue will contain the lengths of the ropes.
        priority_queue<long long, vector<long long>, CustomComparator> pq;

        // Insert all the rope lengths into the priority_queue.
        for (long long i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        long long ans = 0; // Initialize the answer variable to store the minimum cost.

        // Continue the process until there is only one rope left in the priority_queue.
        while (pq.size() > 1)
        {
            // Extract the two smallest ropes from the priority_queue.
            long first = pq.top();
            pq.pop();

            long second = pq.top();
            pq.pop();

            // Calculate the sum of the two smallest ropes.
            long long sum = first + second;

            // Add the sum to the total cost.
            ans += sum;

            // Push the sum back into the priority_queue for the next iteration.
            pq.push(sum);
        }

        // Return the final minimum cost of connecting all the ropes.
        return ans;
    }
};
