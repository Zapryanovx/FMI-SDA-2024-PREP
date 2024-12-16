#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int bfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& groups, int start, int target)
{
    queue<int> q;
    q.push(start);

    unordered_set<int> visited;
    visited.insert(start);

    int dist = 0;
    while (!q.empty())
    {
        int level = q.size();
        for (int i = 0; i < level; i++)
        {
            int current = q.front();
            q.pop();

            if (groups[current] == target && current != start)
            {
                return dist;
            }

            for (int neighbor : graph[current])
            {
                if (!visited.count(neighbor))
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        dist++;
    }

    return INT_MAX;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    unordered_map<int, unordered_set<int>> graph;
    vector<int> groups(nodes + 1, -1);

    for (int i = 0; i < edges; i++)
    {
        int u, w;
        cin >> u >> w;
        graph[u].insert(w);
        graph[w].insert(u);
    }

    for (int i = 1; i <= nodes; i++)
    {
        cin >> groups[i];
    }

    int target;
    cin >> target;

    int minPath = INT_MAX;

    for (int i = 1; i <= nodes; i++)
    {
        if (groups[i] == target)
        {
            int currMin = bfs(graph, groups, i, target);
            minPath = min(minPath, currMin);
        }
    }

    cout << (minPath == INT_MAX ? -1 : minPath);

    return 0;
}
