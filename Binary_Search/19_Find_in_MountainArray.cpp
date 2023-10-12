/*  https://leetcode.com/problems/find-in-mountain-array/description/
LeetCode 1095. Find in Mountain Array

(This problem is an interactive problem.)

You are given a Mountain Array.
A mountian array is the array which is strictly increasing, and then at a certin point, it starts strictly decreasing.
eg - 1 2 3 4 5 3 2 0
             ^
            Peak
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.
If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

Example 1:
-----------
Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.


Example 2:
-----------
Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.


*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

/* Solution : The idea behind it is very simple,
    1: Find the Peak Index in the Mountain Array.  O(logN).
    2: Search for the desired output in the left subhalf (0 to peak).
    3: If Not Found, search in the Right Subhalf (Peak + 1 to n - 1).

    Note: We search in the left subhalf first, because we want the first occurence of the target
*/

class Solution
{
public:
    int findPeak(MountainArray &mountainArr, int n) // Find the Peak Index
    {
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int h = mountainArr.get(mid);
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

    int search_Left_From_Peak(MountainArray &mountainArr, int target, int left, int right) // Search in the Left Sub-Half
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int elem = mountainArr.get(mid);
            if (elem == target)
                return mid;
            else if (elem < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    // Searching in the Right Sub-Array is very slightly different, as the right part is sorted in the DESCENDING ORDER
    int search_Right_from_Peak(MountainArray &mountainArr, int target, int left, int right) // Search in the Right Sub-Half
    {
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int elem = mountainArr.get(mid);

            if (elem == target)
                return mid;
            else if (elem > target) // This part is just opposite from classic Binary Search, because array is sorted in the increasing order.
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr, n);

        int result = -1;

        result = search_Left_From_Peak(mountainArr, target, 0, peak); // search in left subhalf.

        if (result != -1)  // If not found, dont straight away put -1, because it can be found int the right subarray.
            return result; // Return in found.

        result = search_Right_from_Peak(mountainArr, target, peak + 1, n - 1); // If not found in the left sub-array, search for it in the right sub array.

        return result;
    }
};