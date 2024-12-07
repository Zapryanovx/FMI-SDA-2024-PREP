#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        if (p == -1 && !pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }

        else if (p != -1)
        {
            pq.push(p);
        }
    }


    return 0;
}