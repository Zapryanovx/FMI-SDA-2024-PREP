class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;
        for (string str : tokens)
        {
            if (!st.empty() && (str == "+" || str == "-" || str == "*" || str == "/"))
            {
                int left = st.top();
                st.pop();
                int right = st.top();
                st.pop();

                if (str == "+")
                {
                    st.push(right + left);
                }

                else if (str == "-")
                {
                    st.push(right - left);
                }

                else if (str == "*")
                {
                    st.push(right * left);
                }

                else
                {
                    st.push(right / left);
                }

            }

            else
            {
                st.push(std::stoi(str.c_str()));
            }
        }

        return st.top();
    }
};