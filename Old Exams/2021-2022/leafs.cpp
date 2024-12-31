#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr, unordered_map<int, int>& sums)
{
    visited.insert(curr);

    for (auto& nbr : graph[curr])
    {
        sums[curr] += nbr;
        if (!visited.count(nbr))
        {
            dfs(graph, visited, nbr, sums);
        }

        sums[curr] += sums[nbr];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, unordered_set<int>> graph;
    int m, t;
    cin >> m >> t;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
    }

    unordered_map<int, int> sums;
    unordered_set<int> visited;

    for (int i = 0; i < t; i++)
    {
        int curr;
        cin >> curr;

        if (!visited.count(curr))
        {
            dfs(graph, visited, curr, sums);
        }

        cout << sums[curr] << endl;
    }

    return 0;
}
