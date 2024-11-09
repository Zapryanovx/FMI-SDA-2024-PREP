// https://www.hackerrank.com/contests/kontrolno-3/challenges/challenge-4334/submissions/code/1385120838

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;

        vector<int> v(size);
        for (int j = 0; j < size; j++)
        {
            cin >> v[j];
        }

        stack<int> st;
        for (int k = 0; k < size; k++)
        {
            if (st.empty() || v[k] > 0)
            {
                st.push(v[k]);
            }

            else if (!st.empty() && v[k] == -st.top())
            {
                st.pop();
            }

        }

        if (st.empty())
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
