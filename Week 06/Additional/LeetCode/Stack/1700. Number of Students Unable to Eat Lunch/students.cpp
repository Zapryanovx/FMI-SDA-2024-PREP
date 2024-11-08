class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        queue<int> q;
        for (int i = 0; i < students.size(); i++)
        {
            q.push(students[i]);
        }

        stack<int> st;
        for (int i = sandwiches.size() - 1; i >= 0; i--)
        {
            st.push(sandwiches[i]);
        }

        while (true)
        {

            int size = st.size();
            bool hasLunch = false;

            for (int i = 0; i < size; i++)
            {
                if (st.top() == q.front())
                {
                    st.pop();
                    q.pop();
                    hasLunch = true;
                }

                else
                {
                    int temp = q.front();
                    q.pop();
                    q.push(temp);
                }
            }

            if (!hasLunch)
            {
                return st.size();
            }

        }

        return -1;
    }
};