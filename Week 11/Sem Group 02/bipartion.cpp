class Solution {
public:
    bool dfs(int current, unordered_map<int, unordered_set<int>>& graph, unordered_map<int, bool>& colors, bool currentColor = true) {
        auto iter = colors.find(current);
        if (iter != colors.end())
        {
            return iter->second == currentColor;
        }

        colors[current] = currentColor;
        for (auto& neighbor : graph[current])
        {
            if (!dfs(neighbor, graph, colors, !currentColor))
            {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& e : dislikes)
        {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        unordered_map<int, bool> colors;
        for (auto& kvp : graph)
        {
            auto iter = colors.find(kvp.first);
            if (iter == colors.end())
            {
                if (!dfs(kvp.first, graph, colors))
                {
                    return false;
                }
            }
        }

        return true;
    }
};