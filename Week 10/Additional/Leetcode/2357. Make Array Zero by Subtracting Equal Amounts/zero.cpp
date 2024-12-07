class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        int count = 0;
        while (true)
        {
            priority_queue<int, vector<int>, greater<int>> pq;
            for (auto& num : nums)
            {
                if (num > 0)
                {
                    pq.push(num);
                }
            }

            if (pq.empty())
            {
                return count;
            }

            int x = pq.top();
            for (auto& num : nums)
            {
                num -= x;
            }

            count++;
        }

        return count;
    }
};