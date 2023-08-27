/*
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
1482. Minimum Number of Days to Make m Bouquets
Medium

You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Example 0:
                   0  1  2  3  4   5   6   7
Input: bloomDay = [7, 7, 7, 7, 13, 12, 11, 7], m = 2, k = 3

Input Explained:

Flowers 0, 1, 2, 3, 7 will bloom on day 7
Flower 4 will bloom on day 13
Flower 5 will bloom on day 12
Flower 6 will bloom on day 11

Output = 12

Output explained:                               0  1  2  3  4  5  6  7
On 7th day, garden would look like this  ----> [*, *, *, *, _, _, _, *]
So on day 7, we see that we can only form on Bouquet of size 3 that consist of consecutive flowers.

                                                         0  1  2  3  4  5  6  7
Similary on day 11th, Garden would look like this ----> [*, *, *, *, _, _, *, *]
We still cant make 2 Bouquets of size 3 each from consecutive flower.

                                           0  1  2  3  4  5  6  7
On day 12th, Garden looks like this ----> [*, *, *, *, _, *, *, *]
Here we see that, we can make 2 Bouquets size 3 each from consecutive flower.
Bouquet 1 will be made from flowers - 0 1 2   OR  1 2 3
Bouquet 2 will be made from flowers - 5 6 7

Hence, 12 is the OutPut



Example 1:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

Example 2:
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

Example 3:
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.

*/

class Solution
{
public:
    bool isPossible(vector<int> &bloomDay, int days, int m, int k)
    {
        int flowers = 0;  // To store the total consecutive flowers we can add in a Bouquet.
        int bouquets = 0; // To store the total number of Bouquets.

        // Iterate for every element in the array of Days.
        for (int i = 0; i < bloomDay.size(); i++)
        {
            // If the current day is lesser than or equal to 'mid' days, it means we can take a flower.
            if (bloomDay[i] <= days)
            {
                flowers++; // Since we can take a flower, flower incerements.

                if (flowers == k) // If at any point the number of flowers we took is equal to 'k', we can make a Bouquet out of it, so we do bouquets++
                {
                    bouquets++;
                    flowers = 0; // And we reset the number of flowers to zero inorder to find the next consecutive 'k' flowers that can be picked
                }
            }
            else
            {
                flowers = 0; // If the current days is greater than the 'mid' days, means the flower hasent bloomed and so we reset number of flowers we picked, to zero.
            }
        }
        return bouquets >= m; // If we were able to make atleast 'm' Bouquets, we return true, else false
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        /* If the total number of flowers that we need to make 'm' Bouquets is greater than size of the Array
        We definetly CAN NOT make the Bouquets.
        Hence return -1 */
        long long total = (long long)m * k;
        if (total > bloomDay.size())
            return -1;

        /*In the next steps we are finding the Minimum and Maximum days in the Array.
        This will define our Search Space*/
        int left = INT_MAX;
        int right = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            left = min(left, bloomDay[i]);
            right = max(right, bloomDay[i]);
        }

        /*
        WE CAN ALSO DO THIS

        int left = 1;
        int right = 1e9;
        */

        // Binary Search between the Minimum and Maximum Range.
        int ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            /* If it is Possible to make 'm' Bouquets of 'k' size in 'mid' number of days.
            Save 'mid' as a possible answer and try to find even lesser number of days in
            which we can make 'm' Bouquets */
            if (isPossible(bloomDay, mid, m, k))
            {
                ans = mid;
                right = mid - 1; // Eliminate Right half and search for even better answer in Left half
            }
            else // If it is not possible to make 'm' Bouquets in 'mid' days, eliminate left half and search for answer in right half
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};