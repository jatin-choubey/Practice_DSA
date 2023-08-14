#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int i, int j)
{
    int pivot = arr[i];
    int low = i;
    int high = j;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high)
            i++;
        while (arr[j] > pivot && j >= low)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(vector<int> &arr, int i, int j)
{
    if (i < j)
    {
        int partition_index = partition(arr, i, j);
        quickSort(arr, i, partition_index - 1);
        quickSort(arr, partition_index + 1, j);
    }
}
int main()
{
    vector<int> arr = {4, 2, 1, 6, 100, 101, -23, 0, 3, 5};
    quickSort(arr, 0, arr.size() - 1);
    for (auto element : arr)
        cout << element << " ";
    return 0;
}