class Solution {

    void dfs(int curr, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited)
    {
        visited.insert(curr);
        for (auto& nbr : graph[curr])
        {
            if (visited.count(nbr) == 0)
            {
                dfs(nbr, graph, visited);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int, unordered_set<int>> graph;
        unordered_map<int, unordered_set<int>> indegree;
        for (auto& edge : invocations)
        {
            graph[edge[0]].insert(edge[1]);
            indegree[edge[1]].insert(edge[0]);
        }

        unordered_set<int> visited;
        dfs(k, graph, visited);

        bool isPossible = true;
        for (auto& v : visited)
        {
            for (auto& in : indegree[v])
            {
                if (visited.count(in) == 0)
                {
                    isPossible = false;
                    break;
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (isPossible)
            {
                if (visited.count(i) == 0)
                {
                    res.push_back(i);
                }
            }

            else
            {
                res.push_back(i);
            }
        }

        return res;
    }
};