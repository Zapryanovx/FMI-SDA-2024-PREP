class Solution {
public:
    int largestInteger(int num) {

        priority_queue<int> even;
        priority_queue<int> odd;
        string str = to_string(num);

        for (auto& ch : str)
        {
            int digit = ch - '0';
            if (digit % 2 == 0)
            {
                even.push(digit);
            }

            else
            {
                odd.push(digit);
            }
        }

        int res = 0;
        int mul = pow(10, (str.size() - 1));

        for (auto& ch : str)
        {
            int digit = ch - '0';
            if (digit % 2 == 0)
            {
                res += even.top() * mul;
                mul /= 10;
                even.pop();
            }

            else
            {
                res += odd.top() * mul;
                mul /= 10;
                odd.pop();
            }
        }

        return res;
    }
};