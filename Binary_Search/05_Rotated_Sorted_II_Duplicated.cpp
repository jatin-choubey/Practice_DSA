// Same as Rotated Sorted Array part 1. But contains Duplicate Elements.
/*
For Eg. Nums = [3,3,2,1,3,3,3,3]. Target = 2

Just check if Element at Mid is equal to Element at Low and High.
If yes. Increment Low and Decrement High.

if(nums[mid] == nums[low] && nums[mid] == nums[high])
{
    low++;
    high--
}

Rest everything same as Rotated Sorted Array Part 1

*/

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // If found. Return TRUE
            if (nums[mid] == target)
                return true;

            // JUST ADDING THIS LINE EXTRA
            if (nums[mid] == nums[low] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }

            // Checking if the right half is sorted
            else if (nums[mid] <= nums[high])
            {
                // checking if target is present in the right half ??
                if (nums[mid] < target && nums[high] >= target)
                    low = mid + 1;
                else // If Target is NOT present in the right half. Trim down Left Half
                    high = mid - 1;
            }
            else // Left half is sorted
            {
                // Checking if the target is present in the left half ??
                if (nums[mid] > target && nums[low] <= target)
                    high = mid - 1;
                else // If Target is NOT prsent in the left half. Trim down the Left Half.
                    low = mid + 1;
            }
        }

        // Return False if Never Found
        return false;
    }
};