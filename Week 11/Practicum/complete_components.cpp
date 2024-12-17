class Solution {
public:

    void dfs(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, int curr, int& v, int& e)
    {
        visited.insert(curr);
        v++;
        e += graph[curr].size();

        for (auto& nbr : graph[curr])
        {
            if (visited.count(nbr) == 0)
            {
                dfs(graph, visited, nbr, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;

        for (auto& edge : edges)
        {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        unordered_set<int> visited;
        int counter = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited.count(i) == 0)
            {
                int v = 0;
                int e = 0;
                dfs(graph, visited, i, v, e);

                if (v * (v - 1) == e)
                {
                    counter++;
                }
            }
        }

        return counter;
    }
};