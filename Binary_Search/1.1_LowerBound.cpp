#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> nums = {1, 2, 2, 4, 4, 4, 4, 5, 6};
    int target = 4;
    auto it = std::lower_bound(nums.begin(), nums.end(), target);
    cout << distance(nums.begin(), it);
    return 0;
}
