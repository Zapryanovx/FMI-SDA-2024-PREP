class Solution {
    vector<vector<int>> result;

    void dfs(int curr, vector<int>& path, vector<vector<int>>& graph)
    {
        path.push_back(curr);
        if (curr == graph.size() - 1)
        {
            result.push_back(path);
            path.pop_back();
            return;
        }

        for (auto& neighbour : graph[curr])
        {
            dfs(neighbour, path, graph);
        }

        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<int> path;
        dfs(0, path, graph);
        return result;
    }
};