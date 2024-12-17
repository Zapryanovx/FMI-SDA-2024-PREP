#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, unordered_set<int>> graph;

void bfs(int start, unordered_set<int>& visited, unordered_map<int, unordered_set<int>>& graph)
{
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbour : graph[curr])
        {
            if (!visited.count(neighbour))
            {
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
}

int solve()
{
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < v; i++)
    {
        graph[i];
    }

    int u, w;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> w;
        graph[u].insert(w);
        graph[w].insert(u);
    }

    unordered_set<int> visited;
    int count = 0;

    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        if (visited.count(it->first) != 0)
        {
            continue;
        }

        bfs(it->first, visited, graph);
        count++;
    }

    graph.clear();
    return count;
}


int main() {

    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int q;
    cin >> q;

    while (q--)
    {
        cout << solve() << " ";
    }

    return 0;
}
