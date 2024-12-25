#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int from;
    int to;
    int weight;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, s, e;
    cin >> V >> E >> s >> e;

    vector<int> times(V);
    for (int i = 0; i < V; ++i)
    {
        cin >> times[i];
    }

    vector<Edge> graph;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({ u, v, w });
    }

    vector<int> distances(V, INT_MAX);
    distances[s] = 0;

    bool updated = false;
    for (int i = 0; i < V - 1; ++i)
    {
        updated = false;
        for (auto& edge : graph)
        {
            int u = edge.from;
            int v = edge.to;
            int w = edge.weight;

            if (distances[u] != INT_MAX)
            {
                long long waitTime = (distances[u] % times[u] == 0) ? 0 : times[u] - (distances[u] % times[u]);
                long long newTime = distances[u] + waitTime + w;

                if (newTime < distances[v])
                {
                    distances[v] = newTime;
                    updated = true;
                }
            }
        }

        if (!updated)
        {
            break;
        }
    }

    if (distances[e] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << distances[e] << endl;
    }


    return 0;
}
