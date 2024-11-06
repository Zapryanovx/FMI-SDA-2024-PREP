class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> records;
        for (string op : operations)
        {

            if (op == "+")
            {
                int prevOne = records.top();
                records.pop();

                int prevTwo = records.top();
                records.pop();

                records.push(prevTwo);
                records.push(prevOne);
                records.push(prevOne + prevTwo);
            }

            else if (op == "D")
            {
                records.push(records.top() * 2);
            }

            else if (op == "C")
            {
                records.pop();
            }

            else
            {
                records.push(std::stoi(op));
            }
        }

        int sum = 0;
        while (!records.empty())
        {
            sum += records.top();
            records.pop();
        }

        return sum;
    }
};