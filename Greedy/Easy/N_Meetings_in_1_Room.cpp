// Given 'N' meetings with their start and end times, find the maximum number of non-overlapping
// meetings that can be scheduled in one room. Return the count of such non-overlapping meetings.
/*
-- Input -----
Meeting Number : 1 2 3 4 5
Starting Time  : 7 1 0 4 8
Ending   Time  : 8 5 2 9 10

-- Output ---
Maximum meetings that can be arranged in a SINGLE ROOM  :  2

-- Explaination ---
Meeting 3 from (0 - 2)
Meeting 1 from (7 - 8)

*/

// SORT the Meetings based on their ending time.
// Because lesser the ending time, more time will be left to arrange other meetings.

#include <vector>
#include <algorithm>

struct Meeting
{
    int start;
    int end;
};

bool compare(Meeting m1, Meeting m2)
{
    return m1.end < m2.end;
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = end.size(); // Get the size of the arrays

    vector<Meeting> meetings(n); // Make a meetings vector to store both starting and ending time of both the meetings.
    for (int i = 0; i < n; i++)
    {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    // Sort the meetings vector based on the end time using the compare function
    sort(meetings.begin(), meetings.end(), compare);

    int ans = 1;
    int last = meetings[0].end; // Initialize the end time of the first meeting. This is the meeting with smallest Ending Time.

    for (int i = 1; i < n; i++)
    {
        if (last < meetings[i].start)
        {
            /* If the start time of the current meeting is greater than the end time of the last meeting we arranged,
             means the two meetings wont overlap and we can attend this meeting.
             So, update the last end time to the current meetings end time, and increment the answer. */
            last = meetings[i].end;
            ans++;
        }
    }

    return ans;
}
