#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4, 2, 1, 6, 100, 101, -23, 0, 3, 5};
    for (int i = 0; i < arr.size(); i++)
    {
        int partitionIndex = i;
        while (partitionIndex > 0 && arr[partitionIndex] < arr[partitionIndex - 1])
        {
            swap(arr[partitionIndex], arr[partitionIndex - 1]);
            partitionIndex--;
        }
    }
    for (auto i : arr)
        cout << i << " ";
    return 0;
}