class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        queue<pair<int, int>> q;
        for (int i = 0; i < tickets.size(); i++)
        {
            q.push({ tickets[i], i });
        }

        int counter = 0;
        while (!q.empty())
        {
            pair<int, int> customer(q.front().first - 1, q.front().second);
            counter++;

            if (customer.second == k && customer.first == 0)
            {
                return counter;
            }

            else if (customer.first != 0)
            {
                q.pop();
                q.push(customer);
            }

            else
            {
                q.pop();
            }
        }

        return -1;
    }
};