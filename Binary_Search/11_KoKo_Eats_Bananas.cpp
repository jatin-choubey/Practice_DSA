/*
Given a pile of banans. Where piles[i] represents number of bananas in 'i'th pile.
Koko wants to eat all the Bananas within given 'h' hours.
If koko eats all the bananas of the 'i'th pile in one hour, he will not eat any other banana
from the next pile, and waits till the next hour to go to next pile of banans.

Koko likes to eat slowly.

Return the Minimum possible speed required to finish all the Bananas within given 'h' hours.

EXAMPLE:
Input: piles = [3,6,7,11], h = 8
Output: 4

Explain:

In Hour 1 ->  Koko eats all the 3 bananas of pile 0
In hour 2 ->  Koko eats 4 bananas from pile 1 (2 banans left)
In Hour 3 ->  Koko eats the remaining 2 bananas from Pile 1
In Hour 4 ->  Koko eats 4 bananas from Pile 1 (3 Bananas Left)
In Hour 5 ->  Koko eats the remaining 3 Bananas from pile 2
In Hour 6 ->  Koko eats 4 bananas from Pile 3 (7 Bananas left)
In Hour 7 ->  Koko eats another 4 bananas from Pile 3 (3 Bananas left)
In Hour 8 ->  Koko eats the remaining 3 bananas from pile 3
------------ FINISHED ------------


*/

class Solution
{
public:
    // Function to check if it's possible to eat all piles within given hours using a specific eating speed
    bool canEat(vector<int> &piles, int hours, int eatingSpeed)
    {
        double timeTaken = 0;

        // Iterate through each pile
        for (int i = 0; i < piles.size(); i++)
        {
            // Calculate the time needed to eat the current pile at the given eating speed
            double thisPile = (double)piles[i] / eatingSpeed;

            // Round up the time to the nearest integer, as KoKo can't eat a fraction of an hour
            thisPile = ceil(thisPile);

            // Accumulate the time taken to eat this pile
            timeTaken += thisPile;
        }

        // Check if the total time taken to eat all piles is within the given hours
        return timeTaken <= hours;
    }

    // Function to find the minimum eating speed required to eat all piles within given hours
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1;
        int right = INT_MIN; // Initialize right to a very low value
        int ans = -1;

        // Determine the maximum pile size, as eating speed can't be less than the slowest eater's pace
        for (auto pile : piles)
            right = max(right, pile);

        // Binary search for the minimum eating speed
        while (left <= right)
        {
            // Calculate the middle eating speed to consider
            int mid = left + (right - left) / 2;

            // Check if KoKo can eat all piles within the given hours using the middle eating speed
            if (canEat(piles, h, mid))
            {
                // Update the answer and explore lower eating speeds
                ans = mid;
                right = mid - 1;
            }
            else
            {
                // If KoKo can't eat all piles in given hours, explore higher eating speeds
                left = mid + 1;
            }
        }

        // Return the minimum eating speed required to eat all piles within given hours
        return ans;
    }
};
