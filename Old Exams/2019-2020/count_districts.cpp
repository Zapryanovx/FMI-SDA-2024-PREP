#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;

void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr)
{
    visited.insert(curr);

    for (auto& nbr : graph[curr])
    {
        if (visited.count(nbr) == 0)
        {
            dfs(graph, visited, nbr);
        }
    }
}

int countDistricts(unordered_map<int, unordered_set<int>>& graph)
{
    unordered_set<int> visited;
    int res = 0;

    for (auto& it : graph)
    {
        if (visited.count(it.first) == 0)
        {
            dfs(graph, visited, it.first);
            res++;
        }
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--)
    {
        int v, e;
        cin >> v >> e;

        for (int i = 0; i < v; i++)
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

        cout << countDistricts(graph) << " ";
        graph.clear();
    }

    return 0;
}
