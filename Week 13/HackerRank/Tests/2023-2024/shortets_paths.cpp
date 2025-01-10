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
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({ to, weight });
    }

    int s = 1;
    int e = n;

    vector<long long> dist(n + 1, LLONG_MAX);
    vector<long long> ways(n + 1, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[s] = 0;
    ways[s] = 1;
    pq.push({ 0, s });

    while (!pq.empty())
    {
        auto [currDist, u] = pq.top();
        pq.pop();

        if (currDist > dist[u])
        {
            continue;
        }

        for (auto [v, w] : graph[u])
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

    if (dist[e] == LLONG_MAX)
    {
        cout << "-1 0";
    }

    else
    {
        cout << dist[e] << " " << ways[e] << endl;
    }


    return 0;
}
