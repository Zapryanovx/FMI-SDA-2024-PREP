#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    int a = 1;
    int b = n;

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<long long> ways(n + 1, 0);

    dist[a] = 0;
    ways[a] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, a });

    while (!pq.empty())
    {
        auto [currDist, u] = pq.top();
        pq.pop();

        if (currDist > dist[u])
        {
            continue;
        }

        for (auto& [v, w] : graph[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                pq.push({ dist[v], v });
            }

            else if (dist[v] == dist[u] + w)
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }

    }

    if (dist[b] == LLONG_MAX)
    {
        cout << "-1 0";
        return 0;
    }

    cout << dist[b] << " " << ways[b];


    return 0;
}
