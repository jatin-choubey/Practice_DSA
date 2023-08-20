/* TOPOLOGICAL SORT
    KAHN's ALGO
    BFS
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(map<int, vector<int>> &graph, vector<int> &inDegree)
{
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            cout << "Pushing in stack " << i << endl;
            st.push(i);
        }
    }

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        ans.push_back(top);
        for (int i = 0; i < graph[top].size(); i++)
        {
            inDegree[graph[top][i]]--;
            if (inDegree[graph[top][i]] == 0)
            {
                st.push(graph[top][i]);
            }
        }
    }
    return ans;
}
int main()
{
    map<int, vector<int>> graph;
    graph[0] = {1, 2};
    graph[1] = {};
    graph[2] = {3};
    graph[3] = {1};

    vector<int> inDegree = {0, 2, 1, 1};

    vector<int> ans;
    ans = topologicalSort(graph, inDegree);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}