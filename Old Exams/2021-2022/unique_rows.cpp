#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        string curr;
        for (int j = 0; j < m; j++)
        {
            char el;
            cin >> el;
            curr += el;
        }

        mp[curr]++;
    }

    int count = 0;
    for (auto& p : mp)
    {
        if (p.second == 1)
        {
            count++;
        }
    }

    cout << count;

    return 0;
}