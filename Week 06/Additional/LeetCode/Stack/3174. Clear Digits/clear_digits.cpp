class Solution {
public:
    string clearDigits(string s) {

        stack<char> st;

        for (char ch : s)
        {
            if (!st.empty() && isdigit(ch))
            {
                st.pop();
            }

            else if (!isdigit(ch))
            {
                st.push(ch);
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