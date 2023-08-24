/*
Ishika got stuck on an island. There is only one shop on this island and it is
open on all days of the week except for Sunday. Consider following constraints:

'maxFood' – The maximum unit of food you can buy each day.
'days' – Number of days you are required to survive.
'foodDay' – Unit of food required each day to survive.

Currently, it’s Monday, and she needs to survive for the next 'days' days.

Find the minimum number of days on which you need to buy food from the shop
so that she can survive the next 'days' days, or determine that it isn’t possible to survive.
*/

class Solution
{
public:
    // Function to find the minimum number of days to buy food and survive
    int minimumDays(int days, int maxFood, int foodDay)
    {
        // If the amount of food required per day is more than the maximum available,
        // it's not possible to survive, so return -1.
        if (foodDay > maxFood)
            return -1;

        int ans = 1;                   // Initialize the minimum number of days to buy food to 1.
        int total = foodDay * days;    // Calculate the total food required for the given days.
        int initial_MaxFood = maxFood; // Store the initial maximum units of food available.

        // Keep buying food until the maximum available food is greater than or equal to the total required.
        while (maxFood < total)
        {
            ans++;                               // Increment the count of buying days.
            maxFood = maxFood + initial_MaxFood; // Increase the available food units by the initial maximum.
        }

        int sundays = days / 7;          // Calculate the number of Sundays in the given 'days'.
        int buyingdays = days - sundays; // Calculate the number of days when the shop is open.

        // If the number of days required to buy food exceeds the shop open days,
        // it's not possible to survive, so return -1.
        if (ans > buyingdays)
            return -1;

        return ans; // Return the minimum number of days needed to buy food and survive.
    }
};
