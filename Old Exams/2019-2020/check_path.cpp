#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int k;
    cin >> k;

    int start;
    cin >> start;

    int sum = 0;
    for (int i = 1; i < k; i++)
    {
        int v;
        cin >> v;

        if (graph[start][v] == -1)
        {
            cout << -1;
            return 0;
        }

        sum += graph[start][v];
        start = v;
    }

    cout << sum;

    return 0;
}
