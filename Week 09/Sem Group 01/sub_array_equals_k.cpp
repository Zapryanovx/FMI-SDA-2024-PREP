class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> map;
        map[0] = 1;

        int counter = 0;
        int prefSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefSum += nums[i];
            if (map.find(prefSum - k) != map.end())
            {
                counter += map[prefSum - k];
            }

            map[prefSum]++;
        }

        return counter;
    }
};