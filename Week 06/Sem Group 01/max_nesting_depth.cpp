class Solution {
public:
    int maxDepth(string s) {
        
        stack<int> st;

        int maxDepth = 0;
        for(auto& ch: s)
        {
            if(ch == '(')
            {
                st.push(ch);
                maxDepth = max(int(st.size()), maxDepth);
            }

            else if(ch == ')')
            {
                st.pop();
            }
        }

        return maxDepth;
    }
};
