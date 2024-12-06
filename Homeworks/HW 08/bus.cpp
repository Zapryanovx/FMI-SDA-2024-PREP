#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int n, c;
        cin >> n >> c;

        vector<pair<pair<int, int>, int>> groups;
        for (int i = 0; i < n; i++)
        {
            int k, x, y;
            cin >> k >> x >> y;
            groups.push_back({ {x, y}, k });
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& group : groups)
        {
            pq.push({ group.first.first, group.second });
            pq.push({ group.first.second, -group.second });
        }

        int currPass = 0;
        bool canGetAll = true;

        while (!pq.empty())
        {
            int inOut = pq.top().second;
            pq.pop();

            currPass += inOut;

            if (currPass > c)
            {
                canGetAll = false;
                break;
            }
        }

        cout << (canGetAll ? 1 : 0) << endl;
    }

    return 0;
}