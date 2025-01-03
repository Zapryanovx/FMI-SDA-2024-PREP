#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr, vector<int>& groups, int group)
{
    visited.insert(curr);
    groups[curr] = group;

    for (auto& nbr : graph[curr])
    {
        if (visited.count(nbr) == 0)
        {
            dfs(graph, visited, nbr, groups, group);
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, unordered_set<int>> graph;

    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        graph[i];
    }

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    vector<int> groups(v + 1);
    int group = 1;
    unordered_set<int> visited;

    for (auto& it : graph)
    {
        if (visited.count(it.first) == 0)
        {
            dfs(graph, visited, it.first, groups, group);
            group++;
        }
    }

    int k;
    cin >> k;

    while (k--)
    {
        int from, to;
        cin >> from >> to;
        cout << (groups[from] == groups[to]) << " ";
    }

    return 0;
}