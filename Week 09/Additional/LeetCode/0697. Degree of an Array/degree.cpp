class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int, int> freq;
        unordered_map<int, pair<int, int>> startEnd;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;

            if (startEnd.find(nums[i]) == startEnd.end())
            {
                startEnd[nums[i]] = { i, i };
            }

            else
            {
                startEnd[nums[i]].second = i;
            }
        }

        int maxFreq = 0;
        int minDist = INT_MAX;

        for (auto& curr : freq)
        {
            int currNum = curr.first;
            int currFreq = curr.second;

            int currDist = startEnd[currNum].second - startEnd[currNum].first + 1;

            if (maxFreq < currFreq)
            {
                maxFreq = currFreq;
                minDist = currDist;
            }

            if (maxFreq == currFreq)
            {
                minDist = min(minDist, currDist);
            }
        }

        return minDist;
    }
};