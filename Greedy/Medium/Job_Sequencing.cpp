// Given an array of jobs. Each job has an ID, DEADLINE TIME and PROFIT associated.
// Each job can be done in ONE unit of time.
// Find the MAXIMUM PROFIT that one can earn and how many JOBS need to be worked.
/*
Input: ID  DEADLINE  PROFIT
       1      2       605
       2      3       154
       3      4       383
       4      2       717
       5      4       896

Output: {3, 2601}

Explaination:
* Complete Job 5 on day 4, Profit = 0 + 896 = 896

* Complete Job 4 on day 2, Profit = 896 + 717 = 1613

* Complete Job 1 on day 2, But we are already doing Job 4 on day 2.
  So we try to do Job 1 on previous day 1.
  Profit = 1613 + 605 = 2218

* Complete Job 3 on day 4, But we are already doing Job 5 on day 4
  So we try to do Job 3 on previous day 3.
  Profit = 2218 + 383 = 2601

* Complete Job 2 on day 2, but we are doing Job 4 on day 2.
  Try to do Job 2 on previous day 1, but we are already doing Job 1 on day 1.
  No days Left to job now

  Deadline : 1 2 3 4 5
  Jobs ID  : 1 4 _ 3 5

  Total Jobs Done = 4, Total Profit = 2601

*/

// Approach :
/*
Sort the NEW vector containting all three data on the basis of descending order of Profit.
(USING AN EXTERNAL ARRAY TO STORE THE DEADLINES (Of Size maximum Deadline))
Now, we try to do each job on the last Deadline Time if possible.
If we are already doing any Job on deadline time, we do the job on previous free time.
*/

#include <bits/stdc++.h>

// Structure to represent a job with its id, deadline, and profit
struct JOBS
{
    int id;
    int deadline;
    int profit;
};

// Custom comparator function to sort jobs based on profit in descending order
bool cmp(JOBS j1, JOBS j2)
{
    return j1.profit > j2.profit;
}

// Function to perform job scheduling and return the count of scheduled jobs and their total profit
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    vector<JOBS> sorted(n);

    // Convert the 2D vector of jobs into a vector of JOBS structures
    for (int i = 0; i < n; i++)
    {
        sorted[i].id = jobs[i][0];
        sorted[i].deadline = jobs[i][1];
        sorted[i].profit = jobs[i][2];
    }

    // Sort the jobs in descending order of their profits
    sort(sorted.begin(), sorted.end(), cmp);

    // Find the maximum deadline among all jobs
    int maxTime = 0;
    for (int i = 0; i < n; i++)
    {
        maxTime = max(maxTime, sorted[i].deadline);
    }

    // Initialize variables to track the count of scheduled jobs and their total profit
    int count = 0;
    vector<int> helper(maxTime, -1);
    int maxx = 0;

    // Loop through each job and try to schedule it at its latest possible slot
    for (int i = 0; i < n; i++)
    {
        int place = sorted[i].deadline - 1; // Get the latest possible slot for the current job
        for (int j = place; j >= 0; j--)
        {
            if (helper[j] == -1) // If the slot is empty, schedule the job
            {
                helper[j] = sorted[i].id; // Mark the slot as scheduled
                count++;                  // Increment the count of scheduled jobs
                maxx += sorted[i].profit; // Add the profit of the scheduled job to the total profit
                break;                    // Break the loop as the job is scheduled
            }
        }
    }

    // Return the count of scheduled jobs and their total profit in a vector
    return {count, maxx};
}
