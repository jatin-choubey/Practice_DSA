/*
MINIMUM NUMBER OF PLATFORMS

Description: Given the arrival times (at[]) and departure times (dt[]) of n trains at a railway station,
find the minimum number of platforms required at the station so that no train has to wait.

Example:
Input:
at[] = {9, 10, 12, 13, 14}
dt[] = {11, 11, 16, 15, 17}
n = 5

Output:
3 (Minimum 3 platforms are required so that no train has to wait.)

Explanation:
* Train 1 arrives at 9 and departs at 11.
  requiring 1 platform.

* Train 2 arrives at 10 and departs at 11, Train 1 is already at platform 1 (Platform ++)
  requiring 2 platforms.

* Train 3 arrives at 12 and departs at 16, Till this time, both platforms are vacant.
  Still 2 platforms.

* Train 4 arrives at 13 and departs at 15, Train 3 is on platform 1, but platform 2 is vacant.
  Still 2 platforms.

* Train 5 arrives at 14 and departs at 17, (All) the platforms are already occupied by Train 3 and 4. (Platform ++).
  Requiring 3 platforms.

Hence, a minimum of 3 platforms are needed at the station.

*/

#include <bits/stdc++.h>

int calculateMinPlatforms(int at[], int dt[], int n)
{
    // Sort the arrays of arrival and departure times in ascending order
    sort(at, at + n);
    sort(dt, dt + n);

    int platforms = 1;    // Initialize the number of platforms required to 1
    int maxPlatforms = 1; // Initialize the maximum number of platforms required

    int arrivalIndex = 1;   // Pointer to iterate through the arrival times
    int departureIndex = 0; // Pointer to iterate through the departure times

    // Loop through the arrival times array
    while (arrivalIndex < n)
    {
        if (at[arrivalIndex] <= dt[departureIndex])
        {
            // If a train arrives before or at the same time as a departure,
            // increment the number of platforms and update the maximum platforms needed.
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            arrivalIndex++;
        }
        else
        {
            // If a train arrives after a departure, decrease the number of platforms.
            platforms--;
            departureIndex++;
        }
    }

    return maxPlatforms; // Return the maximum platforms needed.
}
