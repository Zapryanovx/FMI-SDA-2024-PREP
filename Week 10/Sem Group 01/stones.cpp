class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq(stones.begin(), stones.end());
        if (pq.size() == 1)
        {
            return pq.top();
        }

        while (pq.size())
        {
            if (pq.size() == 1)
            {
                return pq.top();
            }

            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (x != y)
            {
                pq.push(y - x);
            }

        }

        return 0;
    }
};