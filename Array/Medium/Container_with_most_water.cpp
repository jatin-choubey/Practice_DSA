int maxArea(vector<int> &height)
{
    int volume = 0, ans = 0, i = 0, j = height.size() - 1;
    while (i < j)
    {
        int lower = min(height[i], height[j]);

        ans = max(ans, lower * (j - i));

        while (i < j and height[i] <= lower)
            i++;

        while (i < j and height[j] <= lower)
            j--;
    }
    return ans;
}