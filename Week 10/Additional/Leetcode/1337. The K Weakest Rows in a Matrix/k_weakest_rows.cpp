class Solution {

    struct Comparator
    {
        bool operator()(const pair<vector<int>, int>& lhs, const pair<vector<int>, int>& rhs)
        {
            int first = distance(lhs.first.begin(), find(lhs.first.begin(), lhs.first.end(), 0));
            int second = distance(rhs.first.begin(), find(rhs.first.begin(), rhs.first.end(), 0));

            if (first == second)
            {
                return lhs.second > rhs.second;
            }
            return first > second;
        }
    };

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, Comparator> pq;
        for (int i = 0; i < mat.size(); i++)
        {
            pq.push({ mat[i], i });
        }

        vector<int> res;
        while (k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};