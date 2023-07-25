// Shopping in a Candy Store
/*
You are in a candy store and there is a deal going on.
For every one candy you buy, you get 'K' candies of your choice for free.

You are given an array 'candies' where candies[i] is price of candy at index 'i'.

You have to calculate two things.
1) What is the MINIMUM amount of money you have to spend to buy all the N different candies.
    Soln : Buy the Cheapest candy and pick the 'K' Costliest candies for free.


2) What is the MAXIMUM amount of money you have to spend to buy all the N different candies.
    Soln : Buy the Costliest candy and pick the 'K' Cheapest candies for free.

*/

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N); // Sort the candies in ascending order.

        int a = 0; // These two pointers will help find the Miniumum price to buy N candies.
        int b = N - 1;

        int x = N - 1; // These two pointers will help find the Maximum price to buy N candies.
        int y = 0;

        int mini = 0;
        int maxx = 0;

        while (a <= b && y <= x)
        {
            mini += candies[a]; // Buy the cheapest candy. (from front)
            b = b - K;          // Get the 'K' costliest candies from back for free
            a++;                // Go for next cheap candy

            maxx += candies[x]; // Buy the Costliest candy (from back)
            x--;                // Go for the next costliest candy
            y = y + K;          // Get the 'K' cheapest candies from the front for free.
        }

        return {mini, maxx};
    }
};