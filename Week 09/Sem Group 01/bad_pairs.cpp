class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long n = nums.size();
        long long allPairs = (n * (n - 1)) / 2;
        long long goodPairs = 0;

        unordered_map<int, long long> m;
        for (int i = 0; i < n; i++)
        {
            int target = nums[i] - i;

            if (m.count(target))
            {
                goodPairs += m[target];
            }

            m[target]++;
        }

        return allPairs - goodPairs;
    }
};