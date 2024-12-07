class Solution {
public:
    int fillCups(vector<int>& amount) {

        priority_queue<int> pq(amount.begin(), amount.end());

        int count = 0;
        while (pq.top() != 0)
        {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();

            if (s == 0)
            {
                pq.push(--f);
                pq.push(s);
            }

            else
            {
                pq.push(--f);
                pq.push(--s);
            }

            count++;
        }

        return count;
    }
};