#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;

        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    int k;
    cin >> k;
    vector<int> t(k);
    for (int i = 0; i < k; i++)
    {
        cin >> t[i];
    }

    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    for (auto& el : t)
    {
        dist[el] = 0;
        pq.push({ 0, el });
    }

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
                pq.push({ dist[v], v });
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int query;
        cin >> query;
        cout << dist[query] << endl;
    }

    return 0;
}
