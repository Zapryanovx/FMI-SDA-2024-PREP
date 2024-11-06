class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<char> st;
        string res;

        for (char ch : s)
        {
            if (ch == '(')
            {
                if (!st.empty())
                {
                    res += ch;
                }

                st.push(ch);
            }

            if (ch == ')')
            {
                st.pop();
                if (!st.empty())
                {
                    res += ch;
                }
            }
        }

        return res;
    }
};