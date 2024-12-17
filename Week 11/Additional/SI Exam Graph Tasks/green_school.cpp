//https://www.hackerrank.com/contests/sda-2019-2020-test-5/challenges/challenge-2299

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    int start = 0;
    unordered_map<int, unordered_set<int>> graph;

    for (int i = 0; i < m; i++)
    {
        int u, w;
        cin >> u >> w;

        graph[u].insert(w);
        graph[w].insert(u);

        start = max(start, u);
        start = max(start, w);
    }

    unordered_set<int> visited;
    queue<int> q;
    set<int> kDist;

    q.push(start);
    visited.insert(start);

    int currDist = 0;

    while (!q.empty())
    {

        if (currDist == k)
        {
            while (!q.empty())
            {
                kDist.insert(q.front());
                q.pop();
            }

            break;
        }

        int level = q.size();
        for (int i = 0; i < level; i++)
        {
            int curr = q.front();
            q.pop();

            for (auto& nbr : graph[curr])
            {
                if (visited.count(nbr) == 0)
                {
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }

        currDist++;
    }

    for (auto& it : kDist)
    {
        cout << it << ' ';
    }

    if (!kDist.size())
    {
        cout << -1;
    }

    return 0;
}
