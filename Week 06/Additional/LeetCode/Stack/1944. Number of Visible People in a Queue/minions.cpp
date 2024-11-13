class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        int n = heights.size();
        vector<int> res(n);

        vector<pair<int, int>> minions(n);
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++)
        {
            minions[i] = { heights[i], i };
        }

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first <= minions[i].first)
            {
                res[st.top().second]++;
                st.pop();
            }

            if (!st.empty())
            {
                res[st.top().second]++;
            }

            st.push(minions[i]);
        }

        return res;
    }
};