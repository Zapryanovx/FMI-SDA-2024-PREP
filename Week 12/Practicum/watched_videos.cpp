class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {

        int n = friends.size();
        int currLevel = 0;

        queue<int> q;
        q.push(id);

        unordered_set<int> visited;
        visited.insert(id);

        while (!q.empty() && currLevel < level)
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                int curr = q.front();
                q.pop();

                for (auto& f : friends[curr])
                {
                    if (visited.count(f) == 0)
                    {
                        visited.insert(f);
                        q.push(f);
                    }
                }
            }

            currLevel++;
        }

        if (currLevel != level)
        {
            return {};
        }

        unordered_map<string, int> videoCount;
        while (!q.empty())
        {
            int friendId = q.front();
            q.pop();

            for (auto& video : watchedVideos[friendId])
            {
                videoCount[video]++;
            }
        }

        vector<pair<int, string>> sortedVideos;
        for (auto& p : videoCount)
        {
            sortedVideos.push_back({ p.second, p.first });
        }

        sort(sortedVideos.begin(), sortedVideos.end(), [&](const pair<int, string>& a, const pair<int, string>& b) -> bool {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second < b.second;
            });

        vector<string> res;
        for (auto& p : sortedVideos)
        {
            res.push_back(p.second);
        }

        return res;
    }
};