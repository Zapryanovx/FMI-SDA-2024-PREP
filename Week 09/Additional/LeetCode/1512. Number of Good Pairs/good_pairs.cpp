class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int, int> m;
        int counter = 0;

        for (int n : nums)
        {
            if (m.find(n) != m.end())
            {
                counter += m[n];
            }

            m[n]++;
        }

        return counter;
    }
};