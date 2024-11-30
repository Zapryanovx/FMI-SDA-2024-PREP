class Solution {
public:

    int rev(int num)
    {
        int res = 0;
        while (num)
        {
            res *= 10;
            res += num % 10;
            num /= 10;
        }

        return res;
    }

    int countNicePairs(vector<int>& nums) {

        const int mod = 1e9 + 7;
        int res = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = (nums[i] - rev(nums[i])) % mod;

            res += m[curr];
            res %= mod;

            m[curr]++;
            m[curr] %= mod;
        }

        return res;
    }
};