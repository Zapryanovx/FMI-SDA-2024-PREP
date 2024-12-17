class Solution {

    void dfs(int curr, unordered_set<int>& visited, vector<vector<int>>& isConnected)
    {
        visited.insert(curr);
        for (int j = 0; j < isConnected.size(); j++)
        {
            if (isConnected[curr][j] == 1 && visited.count(j) == 0)
            {
                dfs(j, visited, isConnected);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int res = 0;
        unordered_set<int> visited;

        for (int i = 0; i < n; i++)
        {
            if (visited.count(i) == 0)
            {
                res++;
                dfs(i, visited, isConnected);
            }
        }

        return res;
    }
};