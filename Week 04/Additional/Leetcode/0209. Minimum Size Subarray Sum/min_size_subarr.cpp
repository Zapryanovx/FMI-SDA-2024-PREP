class Solution {
public:
    bool check(vector<long long>& sums, int target, int mid)
    {
        for (size_t i = mid; i < sums.size(); i++)
        {
            if (sums[i] - sums[i - mid] >= target)
            {
                return true;
            }
        }

        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums)
    {

        int left = 1;
        int right = nums.size();

        vector<long long> sums(nums.size() + 1, 0);
        for (size_t i = 1; i <= nums.size(); i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        int ans = INT_MAX;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(sums, target, mid))
            {
                ans = mid;
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }

        if (ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }

};