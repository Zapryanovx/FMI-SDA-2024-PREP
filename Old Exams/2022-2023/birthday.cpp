#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        intervals[i] = { {s, e}, i };
    }

    int target;
    cin >> target;

    sort(intervals.begin(), intervals.end());

    priority_queue<int, vector<int>, greater<int>> seats;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        seats.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        while (!pq.empty() && intervals[i].first.first >= pq.top().first)
        {
            int s = pq.top().second;
            pq.pop();
            seats.push(s);
        }

        if (intervals[i].second == target)
        {
            cout << seats.top();
            return 0;
        }

        pq.push({ intervals[i].first.second, seats.top() });
        seats.pop();
    }

    return 0;
}