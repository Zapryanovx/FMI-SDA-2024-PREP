class Solution {
public:

    void dfs(int curr, unordered_set<int>& visited, vector<vector<int>>& rooms)
    {
        visited.insert(curr);
        for (auto& neighbour : rooms[curr])
        {
            if (visited.count(neighbour) == 0)
            {
                dfs(neighbour, visited, rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        unordered_set<int> visited;
        dfs(0, visited, rooms);

        for (int i = 0; i < rooms.size(); i++)
        {
            if (visited.count(i) == 0)
            {
                return false;
            }
        }

        return true;
    }
};