class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());
        int target = s.size();
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> curr;

            for (int j = i; j < nums.size(); j++)
            {
                curr.insert(nums[j]);

                if (curr.size() == target)
                {
                    res++;
                }
            }
        }

        return res;
    }
};