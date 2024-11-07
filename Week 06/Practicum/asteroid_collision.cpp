class Solution {
public:

    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> stk;
        for (size_t i = 0; i < asteroids.size(); i++)
        {
            bool destroyed = false;

            while (!stk.empty() && asteroids[i] < 0 && stk.top() > 0)
            {
                if (stk.top() < abs(asteroids[i]))
                {
                    stk.pop();
                }

                else if (stk.top() == abs(asteroids[i]))
                {
                    stk.pop();
                    destroyed = true;
                    break;
                }

                else
                {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
            {
                stk.push(asteroids[i]);
            }

        }

        vector<int> res(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--)
        {
            res[i] = stk.top();
            stk.pop();
        }

        return res;
    }
};