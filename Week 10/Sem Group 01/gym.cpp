#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    int beg, end;
    for (int i = 0; i < n; i++)
    {
        cin >> beg >> end;

        if (beg < end)
        {
            v.push_back({ beg, end });
        }
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    int maxSize = 0;
    for (auto& p : v)
    {
        int start = p.first;
        int end = p.second;

        while (!pq.empty() && pq.top() <= start)
        {
            pq.pop();
        }

        pq.push(end);
        maxSize = max(maxSize, int(pq.size()));
    }

    cout << maxSize;

    return 0;
}
