class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {

        sort(a.begin(), a.end());

        long long i = 0;
        long long j = i + m - 1;
        long long ans = INT_MAX;
        while (j < n)
        {
            long long diff = a[j] - a[i];
            ans = min(ans, diff);
            i++;
            j++;
        }
        return ans;
    }
};