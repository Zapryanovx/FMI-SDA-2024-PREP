class Solution {
public:

    double dijkstra(unordered_map<int, unordered_map<int, double>>& graph, int start, int end, int n)
    {
        const int INF = -1;
        vector<double> results(n, INF);
        results[start] = 0;

        unordered_set<int> visited;
        priority_queue<pair<double, int>> pq;
        pq.push({ 1, start });

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            double currDistance = curr.first;
            int v = curr.second;

            if (visited.count(v))
            {
                continue;
            }
            visited.insert(v);

            for (auto it = graph[v].begin(); it != graph[v].end(); it++)
            {
                int u = it->first;
                double vDist = it->second;

                if (results[u] == INF || currDistance * vDist > results[u])
                {
                    results[u] = currDistance * vDist;
                    pq.push({ results[u], u });
                }
            }
        }

        return results[end] != INF ? results[end] : 0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        unordered_map<int, unordered_map<int, double>> graph;

        for (int i = 0; i < n; i++)
        {
            graph[i];
        }

        for (int i = 0; i < edges.size(); i++)
        {
            int u, v;
            double w;
            u = edges[i][0];
            v = edges[i][1];
            w = succProb[i];

            graph[u][v] = w;
            graph[v][u] = w;
        }

        return dijkstra(graph, start_node, end_node, n);
    }
};