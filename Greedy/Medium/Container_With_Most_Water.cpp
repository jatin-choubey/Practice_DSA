// Function to find the maximum water container area formed by two vertical lines represented by 'height'.
// The function takes a reference to a vector 'height' as input and returns an integer as output.
// The function uses a two-pointer approach to find the maximum area between two vertical lines.
// 'i' and 'j' are initialized to the leftmost and rightmost indices of the 'height' vector, respectively.
// The 'ans' variable keeps track of the maximum area found so far.
// The loop continues until the 'i' pointer is less than the 'j' pointer.
// At each step, the 'lower' variable calculates the height of the shorter vertical line between 'height[i]' and 'height[j]'.
// The 'ans' is updated by taking the maximum of its current value and the area calculated by 'lower * (j - i)'.
// Then, the 'i' and 'j' pointers are moved towards each other to potentially find a greater area.
// If 'height[i]' or 'height[j]' is less than or equal to 'lower', we move the pointer towards the center,
// as there is no chance of finding a greater area with the current height.
// The function finally returns the maximum water container area found.

int maxArea(vector<int> &height)
{
    int volume = 0, ans = 0, i = 0, j = height.size() - 1;
    while (i < j)
    {
        int lower = min(height[i], height[j]);

        // Update 'ans' with the maximum of its current value and the area between the vertical lines.
        ans = max(ans, lower * (j - i));

        // Move 'i' towards the right if its height is less than or equal to 'lower'.
        while (i < j and height[i] <= lower)
            i++;

        // Move 'j' towards the left if its height is less than or equal to 'lower'.
        while (i < j and height[j] <= lower)
            j--;
    }

    // Return the maximum water container area found.
    return ans;
}
