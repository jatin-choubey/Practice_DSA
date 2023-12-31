//      FRACTIONAL KNAPSACK
/*

                                      WEIGHTs   VALUEs
Input : vector<pair<int, int>> items = {{50,     40},
                                        {40,     50},
                                        {90,     25},
                                        {120,    100},
                                        {10,     30},
                                        {200,    45}}
Sack_Space = 200

Process:
Calculate Ratios of each Value Weight pair in order to find which weight, value pair giving maximum relative profit.
RATIOs = (Value / Weight)
  0.8
  1.25
  0.2778
  0.8333
  3.0
  0.225

Then sort the new Knap Sack vector (ks) (Containing the Weight, Value and Ratio all together) in decreasing order on the basis of this calculated Ratios.

Now we GREEDILY pick the weight that has the maximum relative Value.

The most optimal way to fill the knapsack is to choose full items with weight 10 and value 30,
weight 40 and value 50, weight 120 and value 100.
Then take weight 30 from the item with weight 50 and value 40.

The total value =  30 + 50 + 100 + (30/50)*(40) = 204.00

Output:  204.00

*/

#include <bits/stdc++.h>
struct knp
{
    int weight;
    int value;
    double ratio;
};

// Custom comparator function to sort the items in descending order based on the ratio (value/weight)
bool cmp(knp r1, knp r2)
{
    return r1.ratio > r2.ratio;
}

// Function to find the maximum value that can be obtained from the items given the sack's capacity
double maximumValue(vector<pair<int, int>> &items, int n, int sack_Space)
{
    // Create a vector of knp (knapsack) structure to store the items with their corresponding weight, value, and ratio
    vector<knp> ks(n);

    // Calculate the ratio (value/weight) for each item and store it in the knapsack structure
    for (int i = 0; i < n; i++)
    {
        double r = (double)items[i].second / (double)items[i].first;
        ks[i].weight = items[i].first;
        ks[i].value = items[i].second;
        ks[i].ratio = r;
    }

    // Sort the items in the knapsack structure in descending order based on their ratio
    sort(ks.begin(), ks.end(), cmp);

    double ANS = 0;

    // Loop through the sorted items in the knapsack structure
    for (int i = 0; i < ks.size(); i++)
    {
        // If the sack has no space left, break the loop as no more items can be added
        if (sack_Space <= 0)
            break;

        // If the current item's weight can fit entirely into the sack,
        if (ks[i].weight <= sack_Space)
        {
            // add its value to the total answer and reduce the sack's remaining space accordingly
            ANS += (double)ks[i].value;
            sack_Space -= ks[i].weight;
        }
        else
        {
            // If the current item's weight is greater than the sack's remaining space,
            // take a fraction of the item and add its value to the total answer
            double val = ((double)sack_Space / (double)ks[i].weight) * double(ks[i].value);
            ANS += val;
            break; // As the sack is now full, break the loop
        }
    }

    // Return the maximum value that can be obtained from the items given the sack's capacity
    return ANS;
}

// OPTIMISED Solution (Removed Use of Extra Vector Space)

#include <bits/stdc++.h>

bool cmp(pair<int, int> v1, pair<int, int> v2)
{
    double r1 = (double)v1.second / (double)v1.first;
    double r2 = (double)v2.second / (double)v2.first;
    return r1 > r2;
}
double maximumValue(vector<pair<int, int>> &items, int n, int sack_Space)
{
    sort(items.begin(), items.end(), cmp);

    double ans = 0;

    for (int i = 0; i < items.size(); i++)
    {
        if (sack_Space <= 0)
            break;

        if (items[i].first <= sack_Space)
        {
            ans += (double)items[i].second;
            sack_Space -= items[i].first;
        }
        else
        {
            double val = ((double)sack_Space / (double)items[i].first) * double(items[i].second);
            ans += val;
            break;
        }
    }
    return ans;
}