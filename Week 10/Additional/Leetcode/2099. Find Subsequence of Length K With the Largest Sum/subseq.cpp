class Solution {

    static bool compare(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.second < rhs.second;
    }

public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        int n = nums.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({ nums[i], i });
        }

        vector<pair<int, int>> v;
        while (k--)
        {
            v.push_back({ pq.top().first, pq.top().second });
            pq.pop();
        }

        sort(v.begin(), v.end(), compare);
        vector<int> res;
        for (auto& x : v)
        {
            res.push_back(x.first);
        }

        return res;
    }
};