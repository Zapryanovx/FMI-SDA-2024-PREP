class Solution {
public:

    stack<char> generateStack(string str)
    {
        stack<char> st;
        for (char ch : str)
        {
            if (ch == '#' && !st.empty())
            {
                st.pop();
            }

            else if (ch == '#')
            {
                continue;
            }

            else
            {
                st.push(ch);
            }
        }

        return st;
    }

    bool backspaceCompare(string s, string t) {

        stack<char> left = generateStack(s);
        stack<char> right = generateStack(t);

        if (left.size() != right.size())
        {
            return false;
        }

        while (!left.empty() && !right.empty())
        {
            if (left.top() != right.top())
            {
                return false;
            }

            left.pop();
            right.pop();
        }

        return true;
    }
};