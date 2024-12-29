class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({ v, w });
            graph[v].push_back({ u, w });
        }

        vector<int> dist(n, INT_MAX);
        vector<vector<int>> done(n, vector<int>(n, 0));

        int reached = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, 0 });
        dist[0] = 0;

        while (!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
            {
                continue;
            }

            reached++;

            for (auto& [neighbor, w] : graph[node])
            {
                int remainingMoves = maxMoves - d;
                if (remainingMoves <= 0)
                {
                    continue;
                }

                int used = min(w, remainingMoves);
                done[node][neighbor] = max(done[node][neighbor], used);

                int dn = d + w + 1;
                if (dn < dist[neighbor] && dn <= maxMoves)
                {
                    dist[neighbor] = dn;
                    pq.push({ dn, neighbor });
                }
            }
        }

        for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            reached += min(w, done[u][v] + done[v][u]);
        }

        return reached;
    }
};