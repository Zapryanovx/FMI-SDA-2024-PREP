class Solution {

    static bool compare(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first == b.first)
        {
            if (a.second * b.second < 0)
            {
                return a.second < b.second;
            }
        }

        return a.first < b.first;
    }

public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size();

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({ times[i][0], i + 1 });
            v.push_back({ times[i][1], -(i + 1) });
        }

        sort(v.begin(), v.end(), compare);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(i);
        }

        unordered_map<int, int> friendOnChair;
        for (auto& p : v)
        {
            int time = p.first;
            int idx = abs(p.second);

            if (p.second < 0)
            {
                int chair = friendOnChair[idx];
                pq.push(chair);
            }

            else
            {
                int chair = pq.top();
                pq.pop();
                friendOnChair[idx] = chair;

                if (idx - 1 == targetFriend)
                {
                    return chair;
                }
            }
        }

        return -1;
    }
};