#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;


int main() {

    int n = 0;
    cin >> n;

    vector<int> trees(n);
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }

    int start = n - 1;
    int maxSize = 0;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= trees[i])
        {
            st.pop();
        }

        st.push(trees[i]);

        if (maxSize <= st.size())
        {
            maxSize = st.size();
            start = i;
        }
    }

    cout << start;

    return 0;
}
