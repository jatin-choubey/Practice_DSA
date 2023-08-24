/*
Index = 0 1 2 3 4 5 6 7 8
Array = 1 2 2 4 4 4 4 5 6   X = 4

Upper bound is the index of first value which is greater than the given integer 'X'.

Output : Index 6

Index = 0 1 2
Array = 1 1 1
X = 1

Index 3 is the index where the element greater than 'X' should possibly be

Output = 3
*/

int upperBound(vector<int> &arr, int x, int n)
{
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] <= x)
        {
            ans = mid + 1; // Mid + 1 could be a possible answer.
            l = mid + 1;   // Search in right if  possible
        }
        else
            r = mid - 1; // Go in left half
    }
    return ans;
}