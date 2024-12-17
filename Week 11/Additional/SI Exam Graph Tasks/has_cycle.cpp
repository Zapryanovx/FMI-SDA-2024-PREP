// https://www.hackerrank.com/contests/sda-homework-10/challenges/-1-12/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, unordered_set<int>> graph;

bool cycleHelper(unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& visited, unordered_set<int>& path, int curr)
{
    visited.insert(curr);
    path.insert(curr);

    for (int nbr : graph[curr])
    {
        if (path.find(nbr) != path.end())
        {
            return true;
        }

        if (visited.find(nbr) != visited.end())
        {
            continue;
        }

        if (cycleHelper(graph, visited, path, nbr))
        {
            return true;
        }
    }

    path.erase(curr);
    return false;
}

bool hasCycle(unordered_map<int, unordered_set<int>>& graph)
{
    unordered_set<int> visited;
    unordered_set<int> path;

    for (auto& it : graph)
    {
        if (visited.find(it.first) == visited.end() && cycleHelper(graph, visited, path, it.first))
        {
            return true;
        }
    }

    return false;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int v, e;
        cin >> v >> e;

        for (int i = 1; i <= v; i++)
        {
            graph[i];
        }

        for (int i = 0; i < e; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;

            graph[x].insert(y);

        }

        if (hasCycle(graph))
        {
            cout << "true ";
        }

        else
        {
            cout << "false ";
        }

        graph.clear();
    }

    return 0;
}
