#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    long long from;
    long long to;
    long long weight;

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<Edge> graph;
    for (long long i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        graph.push_back({ u, v, w });
    }

    vector<long long> distances(n + 1, LLONG_MIN);
    distances[s] = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        for (auto& edge : graph)
        {
            if (distances[edge.from] != LLONG_MIN
                && distances[edge.to] < distances[edge.from] + edge.weight)
            {
                distances[edge.to] = distances[edge.from] + edge.weight;
            }
        }
    }


    if (distances[t] == LLONG_MIN)
    {
        cout << -1;
    }

    else
    {
        cout << distances[t];
    }

    return 0;
}
