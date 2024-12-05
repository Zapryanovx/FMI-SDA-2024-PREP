class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        priority_queue<int> pq(nums.begin(), nums.end());
        long long score = 0;

        for (int i = 0; i < k; i++)
        {
            int maxOf = pq.top();
            pq.pop();
            pq.push(ceil(1.00 * maxOf / 3));

            score += maxOf;
        }

        return score;
    }
};