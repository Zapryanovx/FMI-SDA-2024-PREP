// https://www.hackerrank.com/contests/sda-2021-2022-test-6-christmas/challenges/challenge-2351

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

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

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int i = 0; i < x; i++)
        {
            graph[i];
        }

        for (int i = 0; i < y; i++)
        {
            int u, w;
            cin >> u >> w;

            graph[u].insert(w);
            graph[w].insert(u);

        }

        int res = countDistricts(graph);
        graph.clear();
        cout << res << " ";
    }


    return 0;
}
