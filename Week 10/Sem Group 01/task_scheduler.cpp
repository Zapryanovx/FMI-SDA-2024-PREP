class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<int> pq;
        vector<int> mp(26, 0);

        for (char ch : tasks)
        {
            mp[ch - 'A']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (mp[i])
            {
                pq.push(mp[i]);
            }
        }

        int intervals = 0;
        int gap = n + 1;
        while (!pq.empty())
        {
            vector<int> temp;
            for (int i = 0; i < gap; i++)
            {
                if (!pq.empty())
                {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                }
            }

            for (int task : temp)
            {
                if (task > 0)
                {
                    pq.push(task);
                }
            }

            intervals += pq.empty() ? temp.size() : gap;
        }

        return intervals;
    }
};