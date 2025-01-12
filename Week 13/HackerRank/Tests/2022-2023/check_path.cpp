#include <bits/stdc++.h>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; i++)
    {
        int f, t, w;
        cin >> f >> t >> w;

        graph[f][t] = w;
        graph[t][f] = w;
    }

    int k;
    cin >> k;

    vector<int> path(k);
    for (int i = 0; i < k; i++)
    {
        cin >> path[i];
    }

    int sum = 0;
    for (int i = 1; i < k; i++)
    {
        if (graph[path[i]][path[i - 1]] == INT_MAX)
        {
            cout << -1;
            return 0;
        }

        sum += graph[path[i]][path[i - 1]];
    }

    cout << sum;
    return 0;
}
