#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int l, int mid, int r)
{
    int left = l;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= r)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= r)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = 0; i <= r - l; i++)
    {
        arr[i + l] = temp[i];
    }
}
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}
int main()
{
    vector<int> arr = {4, 2, 1, 6, 100, 101, -23, 0, 3, 5};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}