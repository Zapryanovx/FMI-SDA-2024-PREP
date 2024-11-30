class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {

        unordered_map<int, int> m;
        int at = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
            {
                m[at++] = i;
            }
        }

        vector<int> res;
        for (auto& match : queries)
        {
            if (match > m.size())
            {
                res.push_back(-1);
            }

            else
            {
                res.push_back(m[match]);
            }
        }

        return res;
    }
};