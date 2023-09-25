#include <bits/stdc++.h>
using namespace std;
long long maximumSumOfHeights(vector<int> &maxHeights)
{
    int n = maxHeights.size();
    //===================================================================================================
    // PREVIOUS SMALLER ELEMENT USING STACK
    stack<int> st;
    vector<int> prevSmaller(n, -1); // stores the "index" of previous Smaller Element
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && maxHeights[st.top()] >= maxHeights[i])
        {
            st.pop();
        }

        if (!st.empty())
            prevSmaller[i] = st.top();
        st.push(i);
    }
    cout << "prevSmaller = ";
    for (auto i : prevSmaller)
        cout << i << " ";
    cout << endl;

    //=======================================================================================================
    // NEXT SMALLER ELEMENT USING STACK
    vector<int> nextSmaller(n, n); // stores the "index" of next Smaller Elements
    st = stack<int>();             // new Stack
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && maxHeights[st.top()] >= maxHeights[i])
        {
            st.pop();
        }
        if (!st.empty())
            nextSmaller[i] = st.top();
        st.push(i);
    }
    cout << "nextSmaller = ";
    for (auto i : nextSmaller)
        cout << i << " ";
    cout << endl;
    //=========================================================================================================
    vector<long long> leftSum(n, 0);
    leftSum[0] = maxHeights[0];
    cout << "\nLEFT EQUAL\n";
    for (int i = 1; i < n; i++)
    {
        int prevSmallerIdx = prevSmaller[i];
        int equalCount = i - prevSmallerIdx;
        cout << i << " - " << prevSmallerIdx << " = " << equalCount << endl;
        // all elements from [prevSmallerIdx + 1] to [i] will be set to "maxHeights[i]"

        leftSum[i] = leftSum[i] + ((long long)equalCount * maxHeights[i]);

        if (prevSmallerIdx != -1)
            leftSum[i] += leftSum[prevSmallerIdx];
    }
    cout << "left Sum = ";
    for (auto i : leftSum)
        cout << i << " ";
    cout << endl;

    //========================================================================================================
    vector<long long> rightSum(n, 0);
    rightSum[n - 1] = maxHeights[n - 1];
    cout << "\nNEXT EQUAL\n";
    for (int i = n - 2; i >= 0; i--)
    {
        int nextSmallerIdx = nextSmaller[i];
        int equalCount = nextSmallerIdx - i;
        cout << nextSmallerIdx << " - " << i << " = " << equalCount << endl;
        // all elements from [i] to [nextSmallerIdx - 1] will be set to "maxHeights[i]"

        rightSum[i] = rightSum[i] + ((long long)equalCount * maxHeights[i]);

        if (nextSmallerIdx != n)
            rightSum[i] += rightSum[nextSmallerIdx];
    }
    cout << "right Sum = ";
    for (auto i : rightSum)
        cout << i << " ";
    cout << endl;
    //=============================================================================================================
    long long ans = 0;
    cout << "Total Sum = ";
    for (int i = 0; i < n; i++)
    {
        long long totalSum = leftSum[i] + rightSum[i] - maxHeights[i];
        cout << totalSum << " ";
        ans = max(ans, totalSum);
    }
    cout << endl;
    //===============================================================================================================
    return ans;
}
int main()
{
    vector<int> maxHeights = {1, 1, 1, 2, 6, 5, 4, 1, 1, 1, 2, 8, 2};
    cout << maximumSumOfHeights(maxHeights);
    return 0;
}