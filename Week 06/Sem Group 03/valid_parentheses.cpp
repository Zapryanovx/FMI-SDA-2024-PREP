class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }

            else
            {
                if (stk.empty())
                {
                    return false;
                }

                else if (s[i] == ')' && stk.top() != '(')
                {
                    return false;
                }

                else if (s[i] == ']' && stk.top() != '[')
                {
                    return false;
                }

                else if (s[i] == '}' && stk.top() != '{')
                {
                    return false;
                }

                else
                {
                    stk.pop();
                }
            }
        }

        if (!stk.empty())
        {
            return false;
        }
        return true;
    }
};