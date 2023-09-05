/*  https://leetcode.com/problems/median-of-two-sorted-arrays/description/
4. Median of Two Sorted Arrays
Hard
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        int n1 = a.size();
        int n2 = b.size();
        int n = n1 + n2;
        if (n1 > n2)
            return findMedianSortedArrays(b, a);

        int half = (n1 + n2 + 1) / 2;
        int left = 0, right = n1;
        while (left <= right)
        {
            int mid1 = (left + right) >> 1;
            int mid2 = half - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                    return max(l1, l2);

                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2)
            {
                right = mid1 - 1;
            }
            else
            {
                left = mid1 + 1;
            }
        }
        return 0;
    }
};