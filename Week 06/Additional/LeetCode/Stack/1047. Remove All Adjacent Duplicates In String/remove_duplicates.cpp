class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;
        for (char ch : s)
        {
            if (st.empty() || ch != st.top())
            {
                st.push(ch);
            }

            else
            {
                st.pop();
            }
        }

        string res;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};