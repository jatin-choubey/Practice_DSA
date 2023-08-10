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

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int left = 0;      // Place the left pointer on the starting index
        int right = n - 1; // Place the right pointer on the ending index.
        int ans = 0;
        while (left < right)
        {
            int dist = right - left;                      // Distance between the poles
            int lower = min(height[left], height[right]); // To find the smaller one amongst the two poles.
            int vol = lower * dist;                       // Volume of water that can be stored between the current two poles.
            ans = max(ans, vol);                          // Maximum betweem the current volume and the max.

            while (left < right && height[left] <= lower) // Keep moving the left pointer till it is lesser than or equal to the lower
                left++;

            while (left < right && height[right] <= lower) // Keep moving the right pointer till it is lesser than or equal to the lower
                right--;
        }
        return ans;
    }
};