#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {4, 2, 1, 6, 100, 101, -23, 0, 3, 5};
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    for (auto i : arr)
        cout << i << " ";
    return 0;
}