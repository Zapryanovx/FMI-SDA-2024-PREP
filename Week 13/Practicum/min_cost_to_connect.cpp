struct Edge
{
    int from;
    int to;
    int length;

    bool operator<(const Edge& other) const
    {
        return length > other.length;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int res = 0;
        unordered_set<int> visited;
        priority_queue<Edge> pq;

        if (points.size() >= 2)
        {
            pq.push({ 0, 0, 0 });
        }

        while (!pq.empty() && visited.size() < points.size())
        {
            auto curr = pq.top();
            pq.pop();

            if (visited.count(curr.to))
            {
                continue;
            }

            visited.insert(curr.to);
            res += curr.length;

            for (int i = 0; i < points.size(); i++)
            {
                if (!visited.count(i))
                {
                    int l = abs(points[i][0] - points[curr.to][0]);
                    l += abs(points[i][1] - points[curr.to][1]);
                    pq.push({ curr.to, i, l });
                }
            }
        }

        return res;
    }
};