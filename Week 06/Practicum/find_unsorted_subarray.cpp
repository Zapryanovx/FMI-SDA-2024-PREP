class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        stack<int> st;

        int left = nums.size();
        int right = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                left = min(left, int(st.top()));
                st.pop();
            }

            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
            {
                right = max(right, int(st.top()));
                st.pop();
            }

            st.push(i);
        }

        if (right - left > 0)
        {
            return right - left + 1;
        }
        return 0;

    }
};