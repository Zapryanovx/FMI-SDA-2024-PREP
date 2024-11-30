class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            unordered_set<int> seen;
            for (int j = i + 1; j < n; j++)
            {
                int target = -(nums[i] + nums[j]);

                if (seen.find(target) != seen.end())
                {
                    res.push_back({ nums[i], nums[j], target });

                    while (j + 1 < n && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                }
                seen.insert(nums[j]);
            }
        }

        return res;
    }
};