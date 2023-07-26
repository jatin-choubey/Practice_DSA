#include <bits/stdc++.h>
using namespace std;

int maxThieves(vector<int> rooms, int k)
{
    int ans = 0;
    int n = rooms.size();
    for (int i = 0; i < n; i++)
    {
        cout << "I = " << i << endl;
        if (rooms[i] == 1)
        {
            int ti = i - k;
            int t = 0;
            int found = 0;
            // Going Left
            while (ti != i)
            {
                if (ti >= 0 && rooms[ti] == 0)
                {
                    found++;
                    ans++;
                    cout << "Police at " << i << " Found Thief at " << ti << endl;
                    break;
                }
                ti++;
            }
            if (ti == i) // Not found on left
            {
                // Going Right
                int t = 0;
                while (ti < n - 1 && t < k)
                {
                    if (rooms[ti + 1] == 0)
                    {
                        cout << "Police at " << i << " Found thief at " << ti + 1 << endl;
                        ans++;
                        rooms[ti + 1] = -1;
                        break;
                    }
                    ti++;
                    t++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> rooms = {0, 0, 1, 0, 0, 1, 1, 1, 0};
    int k = 2;
    cout << maxThieves(rooms, k);
    return 0;
}