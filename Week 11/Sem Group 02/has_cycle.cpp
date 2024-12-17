#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_set<int>> graph;

bool dfs(int curr, unordered_map<int, int>& colours, unordered_map<int, unordered_set<int>>& graph)
{
    colours[curr] = 1;

    for (int neighbour : graph[curr])
    {
        if (colours[neighbour] == 1)
        {
            return true;
        }

        if (colours[neighbour] == 2)
        {
            continue;
        }

        if (dfs(neighbour, colours, graph))
        {
            return true;
        }
    }

    colours[curr] = 2;
    return false;
}

bool hasCycle(unordered_map<int, unordered_set<int>>& graph)
{
    unordered_map<int, int> colours;

    for (auto it = graph.begin(); it != graph.end(); it++)
    {
        if (colours.count(it->first) != 0)
        {
            continue;
        }

        if (dfs(it->first, colours, graph))
        {
            return true;
        }
    }

    return false;
}

bool solve()
{
    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= v; i++)
    {
        graph[i];
    }

    int x, y, w;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        graph[x].insert(y);
    }

    bool ans = hasCycle(graph);
    graph.clear();

    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        auto ans = solve() ? "true" : "false";
        cout << ans << " ";
    }

    return 0;
}
