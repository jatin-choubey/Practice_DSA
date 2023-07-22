// Write a Program to determine the minimum number of coins that sum of to the given Amount.
/*
Input : 2516

Output : [1000, 1000, 500, 10, 5, 1]
These are the Minimum number of coins that sum up to the given Amount.

NOTE: The Greedy algo only works here is because the sum of Smaller two coins never exceed the value of Bigger coin.
*/

vector<int> MinimumCoins(int amount)
{
    // Available coin denominations in descending order
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

    // Vector to store the selected coin denominations that sum up to 'amount'
    vector<int> ans;

    // Initialize the index 'i' to iterate through the 'coins' vector
    int i = 0;

    // Continue the loop until the remaining 'amount' becomes zero
    while (amount > 0)
    {
        // Check if the current coin denomination at index 'i' is less than or equal to 'amount'
        if (coins[i] <= amount)
        {
            // Add the current coin denomination to the 'ans' vector
            ans.push_back(coins[i]);

            // Reduce the remaining 'amount' by the value of the selected coin denomination
            amount -= coins[i];
        }
        else
        {
            // If the current coin denomination is larger than 'amount',
            // move to the next smaller denomination by incrementing the index 'i'.
            i++;
        }
    }

    // Return the vector containing the selected coin denominations that make up the 'amount'.
    return ans;
}