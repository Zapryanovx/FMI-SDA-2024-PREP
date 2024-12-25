#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

const int INF = -1;
unordered_map<int, unordered_map<int, int>> graph;

void printSolution(const vector<int>& results, const int start, const int V)
{
    for (int v = 1; v <= V; v++)
    {
        if (v == start)
        {
            continue;
        }

        cout << results[v] << " ";
    }

    cout << endl;
}


void solve(int start, int v)
{
    vector<int> results(v + 1, INF);
    results[start] = 0;

    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int dist, to;
        dist = curr.first;
        to = curr.second;

        if (visited.count(to))
        {
            continue;
        }

        visited.insert(to);

        for (auto it = graph[to].begin(); it != graph[to].end(); it++)
        {
            int u, vDist;
            u = it->first;
            vDist = it->second;

            if (visited.count(u))
            {
                continue;
            }

            if (results[u] == INF || dist + vDist < results[u])
            {
                results[u] = dist + vDist;
                pq.push({ results[u], u });
            }
        }


    }

    printSolution(results, start, v);
}

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int v, e;
        cin >> v >> e;

        for (int i = 1; i <= v; i++)
        {
            graph[i];
        }

        for (int i = 0; i < e; i++)
        {
            int v, u, w;
            cin >> v >> u >> w;

            if (graph[v].count(u) && graph[v][u] <= w)
            {
                continue;
            }

            graph[v][u] = w;
            graph[u][v] = w;
        }

        int start;
        cin >> start;

        solve(start, v);
        graph.clear();
    }

    return 0;
}