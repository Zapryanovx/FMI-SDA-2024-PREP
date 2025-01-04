#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;

void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr, int parent, bool& isCycle)
{
    visited.insert(curr);

    for (int nbr : graph[curr])
    {
        if (!visited.count(nbr))
        {
            dfs(graph, visited, nbr, curr, isCycle);
        }

        else if (nbr != parent)
        {
            isCycle = true;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
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

        unordered_set<int> visited;
        int count = 0;
        for (auto& it : graph)
        {
            if (!visited.count(it.first))
            {
                bool isCycle = false;
                dfs(graph, visited, it.first, -1, isCycle);

                if (isCycle)
                {
                    count++;
                }
            }
        }


        cout << count << endl;

        graph.clear();
        visited.clear();
    }

    return 0;
}