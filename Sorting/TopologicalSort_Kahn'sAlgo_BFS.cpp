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
    graph[0] = {};
    graph[1] = {};
    graph[2] = {};
    graph[3] = {4};
    graph[4] = {};
    graph[5] = {2};
    graph[6] = {1, 3, 4, 5};
    graph[7] = {};

    // In-Degree tells how many paths are entering inside, or ending at the particular node.
    // For example, 2 path are ending at Node 4. One from Node 3 and other from Node 6.
    //                      0  1  2  3  4  5  6  7
    vector<int> inDegree = {0, 1, 1, 1, 2, 1, 0, 0};

    vector<int> ans;
    ans = topologicalSort(graph, inDegree);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}