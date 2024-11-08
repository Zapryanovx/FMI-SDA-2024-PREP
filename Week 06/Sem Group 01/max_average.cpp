class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        deque<int> dq;

        double average = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            dq.push_back(nums[i]);
            sum += nums[i];
            if (dq.size() == k)
            {
                average = max(1.00 * sum / k, average);
                sum -= dq.front();
                dq.pop_front();
            }
        }

        return average;
    }
};