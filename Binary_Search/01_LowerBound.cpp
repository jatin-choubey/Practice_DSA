/*
Index = 0 1 2 3 4 5 6 7 8
Array = 1 2 2 4 4 4 4 5 6   X = 4

Lower bound means which is the first position at which the Integer 'X' is occouring

Output : Index 3
*/

int lowerBound(vector<int> arr, int n, int x)
{
    int l = 0, r = n - 1;
    int ans = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;   // Maybe the lower bound
            r = mid - 1; // Look for more small elements on left half
        }
        else
            l = mid + 1; // Look in right half
    }
    return ans;
}
