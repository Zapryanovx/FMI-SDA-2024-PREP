#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, int n, vector<vector<int>>& trees, int& minX, int& maxX, int& minY, int& maxY)
{
    if (x < 0 || x >= n || y < 0 || y >= n || trees[x][y] == 0)
    {
        return;
    }

    trees[x][y] = 0;
    minX = min(minX, x);
    maxX = max(maxX, x);
    minY = min(minY, y);
    maxY = max(maxY, y);

    dfs(x + 1, y, n, trees, minX, maxX, minY, maxY);
    dfs(x - 1, y, n, trees, minX, maxX, minY, maxY);
    dfs(x, y + 1, n, trees, minX, maxX, minY, maxY);
    dfs(x, y - 1, n, trees, minX, maxX, minY, maxY);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> trees(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> trees[i][j];
        }
    }

    priority_queue<int> results;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (trees[i][j] == 1)
            {
                int minX = i, maxX = i, minY = j, maxY = j;
                dfs(i, j, n, trees, minX, maxX, minY, maxY);

                int area = (maxX - minX + 1) * (maxY - minY + 1);
                results.push(area);
            }
        }
    }

    while (!results.empty())
    {
        cout << results.top() << " ";
        results.pop();
    }

    return 0;
}
