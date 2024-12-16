#include <bits/stdc++.h>
using namespace std;

unordered_map<char, unordered_set<char>> graph;

vector<char> topological_bfs(unordered_map<char, unordered_set<char>>& graph)
{
    unordered_map<char, int> indegree;

    for (auto& [v, _] : graph)
    {
        indegree[v] = 0;
    }

    for (auto& [v, children] : graph)
    {
        for (char child : children)
        {
            indegree[child]++;
        }
    }

    queue<char> q;
    vector<char> order;

    for (auto& [v, d] : indegree)
    {
        if (d == 0)
        {
            q.push(v);
        }
    }

    while (!q.empty())
    {
        char curr = q.front();
        q.pop();
        order.push_back(curr);

        for (char neighbour : graph[curr])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return order;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        string word1 = words[i];
        string word2 = words[i + 1];
        size_t minLength = min(word1.size(), word2.size());

        for (size_t j = 0; j < minLength; j++)
        {
            if (word1[j] != word2[j])
            {
                graph[word1[j]].insert(word2[j]);
                break;
            }
        }
    }

    vector<char> res = topological_bfs(graph);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}
