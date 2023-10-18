/*
Program to find the nth Fibonacci Number, where the first two numbers are 0 and 1 and the next number is the sum of previous two numbers.
0 1 2 3 4 5 6 7 ....
0 1 1 2 3 5 8 13 ...

*/
#include <bits/stdc++.h>
using namespace std;
/*
TC = O(n) , Because every number is being calculated for once.
SC = O(n)"Recursion Stack Space" + O(n)"dp array" = O(2n) ~ O(n)
*/
int fib(int n, int *dp) // Recursion + Memoization (Top Down)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)  // If the number is already stored in the look-up table (means its value is already calculated)
        return dp[n]; // Straight away return its value without calculating it.

    // If the number was not stored in the look up table, we need to find the number.
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

    // int num1 = fib(n - 1, dp);
    // int num2 = fib(n - 2, dp);
    // dp[n] = num1 + num2;

    // return dp[n];
}
int memoization(int n)
{
    cout << "From Memoization = ";
    int dp[n + 1]; // creating a look up table called 'dp'

    memset(dp, -1, sizeof dp);

    return fib(n, dp);
}

int tabulation(int n) // Bottom Up
{
    cout << "From Tabulation = ";
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int space_optimized(int n)
{
    cout << "From Space OPtimized = ";
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    int n = 7;
    cout << "Press 1 for Memoization(Top Down), 2 for Tabulation(Bottom Up) and 3 for Space Optimized\n";
    int choice;
    cin >> choice;
    if (choice == 1)
        cout << memoization(n);
    else if (choice == 2)
        cout << tabulation(n);
    else if (choice == 3)
        cout << space_optimized(n);
    return 0;
}
