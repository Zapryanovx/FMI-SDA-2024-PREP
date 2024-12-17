class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> visited;

        for(auto& edge: edges)
        {
            if(visited.count(edge[0]) != 0)
            {
                return edge[0];
            }

            if(visited.count(edge[1]) != 0)
            {
                return edge[1];
            }

            visited.insert(edge[0]);
            visited.insert(edge[1]); 
        }

        return -1;
    }
};
