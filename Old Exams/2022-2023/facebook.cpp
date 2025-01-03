#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;

void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr, int& groupCount)
{
    visited.insert(curr);
    groupCount++;

    for (auto& nbr : graph[curr])
    {
        if (visited.count(nbr) == 0)
        {
            dfs(graph, visited, nbr, groupCount);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e, k;
    cin >> n >> e >> k;

    for (int i = 0; i < n; i++)
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

    unordered_set<int> visited;
    int groupCount = 0;
    int res = 0;

    for (auto& p : graph)
    {
        if (visited.count(p.first) == 0)
        {
            dfs(graph, visited, p.first, groupCount);

            if (groupCount % k == 0)
            {
                res++;
            }

            groupCount = 0;
        }
    }

    cout << res;

    return 0;

}
