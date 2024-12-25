class Solution {
public:
    const int INF = -1;

    int calculateMaxDistance(vector<int>& results)
    {
        if (find(results.begin() + 1, results.end(), INF) != results.end())
        {
            return -1;
        }

        return *max_element(results.begin() + 1, results.end());
    }

    int dijkstra(std::unordered_map<int, std::unordered_map<int, int>>& graph, const int start, const int V)
    {
        vector<int> results(V + 1, INF);
        results[start] = 0;

        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, start });

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();

            int currDist, v;
            currDist = curr.first;
            v = curr.second;

            if (visited.count(v))
            {
                continue;
            }

            visited.insert(v);

            for (auto it = graph[v].begin(); it != graph[v].end(); it++)
            {
                int u, vertexDist;
                u = it->first;
                vertexDist = it->second;

                if (visited.count(u))
                {
                    continue;
                }

                if (results[u] == INF || currDist + vertexDist < results[u])
                {
                    results[u] = currDist + vertexDist;
                    pq.push({ results[u], u });
                }

            }
        }

        return calculateMaxDistance(results);

    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, unordered_map<int, int>> graph;

        for (int i = 1; i <= n; i++)
        {
            graph[i];
        }

        for (int i = 0; i < times.size(); i++)
        {
            int v, u, w;
            v = times[i][0];
            u = times[i][1];
            w = times[i][2];

            graph[v][u] = w;
        }

        return dijkstra(graph, k, n);
    }
};