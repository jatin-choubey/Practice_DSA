#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4, 2, 1, 6, 100, 101, -23, 0, 3, 5};
    for (int i = 0; i < arr.size(); i++)
    {
        int minimum = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[minimum] > arr[j])
                minimum = j;
        }
        swap(arr[i], arr[minimum]);
    }
    for (auto i : arr)
        cout << i << " ";
    return 0;
}