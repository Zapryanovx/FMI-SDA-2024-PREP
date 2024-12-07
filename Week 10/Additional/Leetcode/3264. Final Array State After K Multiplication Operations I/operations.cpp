class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({ nums[i], i });
        }

        while (k--)
        {
            pair<int, int> curr = pq.top();
            pq.pop();
            pq.push({ curr.first * multiplier, curr.second });
        }

        vector<int> res(nums.size());
        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();

            res[curr.second] = curr.first;

        }

        return res;
    }
};