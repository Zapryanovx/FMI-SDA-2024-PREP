class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        unordered_map<int, int> indegree;
        for (auto& edge : edges)
        {
            indegree[edge[1]]++;
        }

        int champ = -1;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                if (champ == -1)
                {
                    champ = i;
                }

                else
                {
                    return -1;
                }
            }
        }

        return champ;
    }

};