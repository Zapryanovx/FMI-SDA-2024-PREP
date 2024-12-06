class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while (!pq.empty())
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            res.push_back(b);
            res.push_back(a);
        }

        return res;
    }
};