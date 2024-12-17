// https://www.hackerrank.com/contests/sda-2021-2022-test-6-christmas/challenges/challenge-2852/problem

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, unordered_set<int>> graph;

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

void countGroups(unordered_map<int, unordered_set<int>>& graph, vector<int>& groups)
{
    unordered_set<int> visited;
    int group = 1;

    for (auto& it : graph)
    {
        if (visited.count(it.first) == 0)
        {
            dfs(graph, visited, it.first, groups, group);
            group++;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        graph[i];
    }

    for (int i = 0; i < e; i++)
    {
        int u, w;
        cin >> u >> w;

        graph[u].insert(w);
        graph[w].insert(u);
    }

    int k;
    cin >> k;

    vector<int> groups(v + 1, -1);
    countGroups(graph, groups);

    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << (groups[l] == groups[r]) << " ";
    }

    return 0;
}