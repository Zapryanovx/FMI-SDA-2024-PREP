class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        unordered_set<int> uniqueEls;
        int left = 0, currSum = 0, maxSum = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            while (uniqueEls.find(nums[right]) != uniqueEls.end())
            {
                uniqueEls.erase(nums[left]);
                currSum -= nums[left++];
            }

            uniqueEls.insert(nums[right]);
            currSum += nums[right];

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};