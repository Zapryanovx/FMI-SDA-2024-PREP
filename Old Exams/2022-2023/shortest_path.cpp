#include <bits/stdc++.h>
using namespace std;

int bfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& forbidden, int beg, int end)
{
    if (beg == end)
    {
        return 0;
    }

    unordered_set<int> visited;
    queue<int> q;

    q.push(beg);
    visited.insert(beg);

    int len = 0;
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            int curr = q.front();
            q.pop();

            for (int nbr : graph[curr])
            {
                if (nbr == end)
                {
                    return len + 1;
                }

                if (!visited.count(nbr) && !forbidden.count(nbr))
                {
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }

        len++;
    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> graph;

    for (int i = 0; i < n; i++)
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

    int p;
    cin >> p;

    vector<int> path(p);
    for (int i = 0; i < p; i++)
    {
        cin >> path[i];
    }

    unordered_set<int> forbidden(path.begin(), path.end());
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int curr;
        cin >> curr;
        forbidden.insert(curr);
    }

    forbidden.erase(path[0]);
    int from, to;
    from = path[0];
    int res = 0;

    for (int i = 1; i < path.size(); i++)
    {
        to = path[i];
        forbidden.erase(to);
        res += bfs(graph, forbidden, from, to);
        from = to;
    }

    cout << res;

    return 0;
}
