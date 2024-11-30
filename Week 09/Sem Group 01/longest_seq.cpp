class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }

        unordered_set<int> s(nums.begin(), nums.end());

        int longestSeq = 0;

        int curr = nums[0];
        int currSeq = 0;

        for (int& num : nums)
        {
            if (!s.count(num - 1))
            {
                curr = num;
                currSeq = 1;
            }

            while (s.count(curr + 1))
            {
                curr++;
                currSeq++;
            }

            longestSeq = max(longestSeq, currSeq);
        }

        return longestSeq;
    }
};