class Solution {
public:

    vector<int> topological_bfs(unordered_map<int, unordered_set<int>>& graph)
    {
        unordered_map<int, int> indegree;
        for (auto& [v, _] : graph)
        {
            indegree[v] = 0;
        }

        for (auto& [v, children] : graph)
        {
            for (int child : children)
            {
                indegree[child]++;
            }
        }

        queue<int> q;
        vector<int> order;

        for (auto& [v, d] : indegree)
        {
            if (d == 0)
            {
                q.push(v);
                order.push_back(v);
            }
        }

        unordered_set<int> visited(order.begin(), order.end());
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbour : graph[curr])
            {
                if (visited.find(neighbour) == visited.end())
                {
                    indegree[neighbour]--;
                }

                if (indegree[neighbour] == 0)
                {
                    visited.insert(neighbour);
                    q.push(neighbour);
                    order.push_back(neighbour);
                }
            }
        }

        return order;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < numCourses; i++)
        {
            graph[i] = {};
        }

        for (auto& edge : prerequisites)
        {
            int advanced = edge[0];
            int beginner = edge[1];
            graph[beginner].insert(advanced);
        }

        vector<int> order = topological_bfs(graph);
        return order.size() == numCourses ? order : vector<int>();
    }
};