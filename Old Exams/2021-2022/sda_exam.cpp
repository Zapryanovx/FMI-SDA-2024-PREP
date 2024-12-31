#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;

void bfs(unordered_map<int, unordered_set<int>>& graph, int start, vector<int>& dist)
{
    queue<int> q;
    q.push(start);
    unordered_set<int> visited;
    visited.insert(start);
    int currLevel = 6;
    while (!q.empty())
    {
        int level = q.size();
        for (int i = 0; i < level; i++)
        {
            auto curr = q.front();
            q.pop();

            for (auto& nbr : graph[curr])
            {
                if (!visited.count(nbr))
                {
                    visited.insert(nbr);
                    q.push(nbr);
                    dist[nbr] = currLevel;
                }
            }
        }

        currLevel += 6;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            graph[i];
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].insert(v);
            graph[v].insert(u);
        }

        vector<int> dist(n + 1, -1);
        int start;
        cin >> start;

        dist[start] = 0;
        bfs(graph, start, dist);
        for (int i = 1; i <= n; i++)
        {
            if (start == i)
            {
                continue;
            }

            cout << dist[i] << " ";
        }
        cout << endl;

        graph.clear();
    }



    return 0;
}