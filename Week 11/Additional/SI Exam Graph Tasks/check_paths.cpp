// https://www.hackerrank.com/contests/sda-2019-2020-exam-2e3nr4rr/challenges/challenge-2353

#include <bits/stdc++.h>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        graph[x][y] = w;
        graph[y][x] = w;
    }

    int k;
    cin >> k;

    int start;
    cin >> start;

    int sum = 0;
    for (int i = 0; i < k - 1; i++)
    {
        int v;
        cin >> v;

        if (graph[start][v] != -1)
        {
            sum += graph[start][v];
        }

        else
        {
            cout << -1;
            return 0;;
        }

        start = v;
    }

    cout << sum;

    return 0;
}
