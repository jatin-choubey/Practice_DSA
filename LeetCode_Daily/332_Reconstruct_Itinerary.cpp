#include <bits/stdc++.h>
using namespace std;
unordered_map<string, vector<string>> createAdjList(vector<vector<string>> &tickets)
{
    unordered_map<string, vector<string>> adjList;
    for (const vector<string> &ticket : tickets)
    {
        adjList[ticket[0]].push_back(ticket[1]);
    }

    for (auto &entry : adjList)
    {
        sort(entry.second.begin(), entry.second.end());
    }
    return adjList;
}

void dfs(unordered_map<string, vector<string>> &adjList, string start, vector<string> &ans)
{
    vector<string> &destinations = adjList[start];
    while (!destinations.empty())
    {
        string next = destinations.front();
        destinations.erase(destinations.begin());
        dfs(adjList, next, ans);
    }
    ans.push_back(start);
}

int main()
{
    vector<vector<string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    unordered_map<string, vector<string>> adjList;

    adjList = createAdjList(tickets);

    for (auto i : adjList)
    {
        string from = i.first;
        cout << from << " -> ";
        for (auto to : i.second)
        {
            cout << to << ", ";
        }
        cout << endl;
    }

    string start = "JFK";

    vector<string> ans;

    dfs(adjList, start, ans);
    // reverse(ans.begin(), ans.end());
    for (auto I : ans)
        cout << I << "  ";
    cout << endl;
    ans.clear();
    tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    adjList = createAdjList(tickets);
    dfs(adjList, start, ans);
    reverse(ans.begin(), ans.end());
    for (auto I : ans)
        cout << I << "  ";
    /*
Reconstruct Itinerary
You are given a list of airline tickets where tickets[i] = [destinationsi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs destinations "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.



Example 1:


Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:


Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

    */

    return 0;
}