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

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        bool isLongPath = false;

        while (!st.empty() && st.top() > 0 && v[i] < 0)
        {
            if (st.top() == abs(v[i]))
            {
                st.pop();
                isLongPath = true;
                break;
            }

            else if (st.top() > abs(v[i]))
            {
                isLongPath = true;
                break;
            }

            else
            {
                st.pop();
            }
        }

        if (!isLongPath)
        {
            st.push(v[i]);
        }
    }

    vector<int> res(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        res[i] = st.top();
        st.pop();
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}