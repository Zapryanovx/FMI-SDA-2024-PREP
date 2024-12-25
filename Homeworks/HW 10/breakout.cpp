#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

struct Cell
{
    int row;
    int col;
    int time;

    bool operator>(const Cell& other) const
    {
        return time > other.time;
    }
};

bool isValid(int row, int col, int n, int m)
{
    return row >= 0 && row < n && col >= 0 && col < m;
}

int dijkstra(vector<vector<char>>& grid, int startRow, int startCol)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> distance(n, vector<int>(m, INF));
    distance[startRow][startCol] = 0;

    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    pq.push({ startRow, startCol, 0 });

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int row = curr.row;
        int col = curr.col;
        int time = curr.time;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if (!isValid(newRow, newCol, n, m))
            {
                return time;
            }

            if (visited[newRow][newCol])
            {
                continue;
            }

            visited[newRow][newCol] = true;
            int newTime = time + (grid[newRow][newCol] == '#' ? 1 : 0);
            pq.push({ newRow, newCol, newTime });
        }
    }

    return INF;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int maxTime = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {

                int time = dijkstra(grid, i, j);
                bool exited = time < INF;

                if (exited)
                {
                    if (time > maxTime)
                    {
                        maxTime = time;
                        count = 1;
                    }

                    else if (time == maxTime)
                    {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
