#include <bits/stdc++.h>
using namespace std;

int result = 0;

int dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr)
{
    if (graph[curr].size() == 0)
    {
        return 1;
    }

    visited.insert(curr);
    int children = 1;

    for (auto& val : graph[curr])
    {
        if (!visited.count(val))
        {
            children += dfs(graph, visited, val);
        }
    }

    if (children % 2 == 0)
    {
        result++;
        return 0;
    }

    return children;
}

int main() {

    int v, e;
    cin >> v >> e;

    unordered_map<int, unordered_set<int>> graph(v + 1);

    for (int i = 0; i < e; i++)
    {
        int u, w;
        cin >> u >> w;
        graph[u].insert(w);
        graph[w].insert(u);
    }

    unordered_set<int> visited;
    dfs(graph, visited, 1);

    cout << result - 1;

    return 0;
}
