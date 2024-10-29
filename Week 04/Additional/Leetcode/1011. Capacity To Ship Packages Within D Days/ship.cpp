class Solution {

    bool check(vector<int>& weights, int mid, int days)
    {
        int currWeight = 0;
        int currDays = 1;
        for (size_t i = 0; i < weights.size(); i++)
        {
            currWeight += weights[i];

            if (currWeight > mid)
            {
                currDays++;
                currWeight = weights[i];
            }

        }

        return currDays <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {

        int left = *max_element(weights.begin(), weights.end());
        int right = left * weights.size();

        int ans = INT_MAX;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(weights, mid, days))
            {
                ans = mid;
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};