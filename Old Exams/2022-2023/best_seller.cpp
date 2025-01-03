#include <bits/stdc++.h>
using namespace std;


unordered_map<int, int> bestItem;
unordered_map<int, int> counterItem;

queue<pair<int, int>> q;
set<int> times;
int maxTime = -1;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int id, time;
        cin >> id >> time;
        q.push({ id, time });
        times.insert(time);
        maxTime = max(maxTime, time);
    }

    long long maxPair = 0;
    long long maxId = -1;

    while (!q.empty())
    {
        int currId = q.front().first;
        counterItem[currId]++;
        if (counterItem[currId] >= maxPair)
        {
            maxPair = counterItem[currId];
            maxId = currId;
        }

        bestItem[q.front().second] = maxId;
        q.pop();
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int x;
        cin >> x;

        if (x >= maxTime)
        {
            cout << bestItem[maxTime] << endl;
            continue;
        }

        auto temp = times.lower_bound(x);
        if (x < *temp)
        {
            if (temp == times.begin())
            {
                cout << -1 << endl;
                continue;
            }

            x = *(--temp);
        }

        else
        {
            x = *temp;
        }

        cout << bestItem[x] << endl;
    }

    return 0;
}