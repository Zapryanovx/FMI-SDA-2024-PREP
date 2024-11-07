class Solution {
public:
    int maxDepth(string s) {

        stack<int> st;

        int maxDepth = -1;
        for (char ch : s)
        {
            if (ch == '(')
            {
                st.push(ch);
                maxDepth = max(int(st.size()), maxDepth);
            }

            if (ch == ')')
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
        }

        return maxDepth;
    }
};