// https://www.hackerrank.com/contests/sda-20232024-test-4/challenges/challenge-4446

#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int target;
        cin >> target;

        pq.push(target);
    }

    int count = 0;
    bool isPossible = false;
    while (pq.size() >= 2)
    {
        if (pq.top() >= s)
        {
            isPossible = true;
            cout << count << endl;
            break;
        }

        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();

        pq.push(f + 2 * s);
        count++;
    }

    if (!isPossible)
    {
        cout << -1 << endl;
    }

    return 0;
}