class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        unordered_set<int> visited;

        queue<int> q;
        q.push(source);
        visited.insert(source);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            if (curr == destination)
            {
                return true;
            }

            for (auto& neighbour : graph[curr])
            {
                if (visited.count(neighbour) == 0)
                {
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }

        return false;
    }
};