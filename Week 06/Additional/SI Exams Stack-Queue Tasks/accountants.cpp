// https://www.hackerrank.com/contests/sda-2020-2021-test5-trgdcw/challenges/challenge-2712

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    stack<int> numbers;
    stack<int> undo_stack;

    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 0)
        {
            numbers.push(v[i]);
            while (!undo_stack.empty())
            {
                undo_stack.pop();
            }

        }

        else if (v[i] == -1)
        {
            if (!numbers.empty())
            {
                undo_stack.push(numbers.top());
                numbers.pop();
            }
        }

        else if (v[i] == -2)
        {
            if (!undo_stack.empty())
            {
                numbers.push(undo_stack.top());
                undo_stack.pop();
            }
        }
    }

    int sum = 0;
    while (!numbers.empty())
    {
        sum += numbers.top();
        numbers.pop();
    }

    cout << sum;

    return 0;
}
