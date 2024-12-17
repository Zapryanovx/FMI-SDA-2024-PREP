#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

void printResults(size_t start, vector<int>& res)
{
    int mul = 6;
    int distance;

    for (size_t v = 1; v < res.size(); v++)
    {
        if (v == start)
        {
            continue;
        }

        distance = res[v] ? res[v] * mul : -1;
        cout << distance << " ";
    }

    cout << endl;
}


void bfs(int start, vector<int>& res, unordered_map<int, unordered_set<int>>& graph)
{
    queue<int> q;
    q.push(start);

    unordered_set<int> visited;
    visited.insert(start);

    int level = 0;
    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            int curr = q.front();
            q.pop();

            res[curr] = level;
            auto children = graph[curr];
            for (auto it = children.begin(); it != children.end(); it++)
            {
                if (!visited.count(*it))
                {
                    q.push(*it);
                    visited.insert(*it);
                }
            }
        }

        level++;
    }
}

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        unordered_map<int, std::unordered_set<int>> graph;

        int V, E, start, v, w;
        cin >> V >> E;

        for (int i = 0; i < E; i++)
        {
            cin >> v >> w;
            graph[v].insert(w);
            graph[w].insert(v);
        }

        cin >> start;

        vector<int> res(V + 1);
        bfs(start, res, graph);
        printResults(start, res);
    }
}