class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        map<int, int> m;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (k == 0)
            {
                if (it->second > 1)
                {
                    count++;
                }
            }

            else
            {
                if (m.count(it->first + k))
                {
                    count++;
                }
            }
        }

        return count;
    }
};