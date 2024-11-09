#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, t;
    cin >> n >> m >> t;

    queue<pair<long long, long long>> apples;
    long long x, y;

    while (cin >> x >> y)
    {
        apples.push({ x - 1, y - 1 });
    }

    bool field[1000][1000]{};
    long long counter = 0;

    for (int i = 0; i <= t; i++)
    {
        int size = apples.size();
        for (int j = 0; j < size; j++)
        {
            pair<int, int> curr = apples.front();
            apples.pop();

            if (curr.first < 0 || curr.second < 0 || curr.first >= n || curr.second >= m)
            {
                continue;
            }

            if (field[curr.first][curr.second])
            {
                continue;
            }

            field[curr.first][curr.second] = true;
            counter++;

            apples.push({ curr.first - 1, curr.second });
            apples.push({ curr.first, curr.second - 1 });
            apples.push({ curr.first, curr.second + 1 });
            apples.push({ curr.first + 1, curr.second });

        }
    }

    cout << n * m - counter;

    return 0;
}