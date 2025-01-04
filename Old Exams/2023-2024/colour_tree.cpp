#include <bits/stdc++.h>
using namespace std;

void dfs(size_t node, vector<vector<long long>>& tree, vector<bool>& colored, vector<int>& parent, int& count)
{
    for (auto& n : tree[node])
    {
        dfs(n, tree, colored, parent, count);
    }

    if (!colored[node])
    {
        count++;
        colored[node] = true;
        colored[parent[node]] = true;
        colored[parent[parent[node]]] = true;

        for (auto& el : tree[parent[node]])
        {
            colored[el] = true;
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> tree(n);
    vector<bool> colored(n, false);
    vector<int> parent(n, 0);

    for (int i = 0; i < n; i++)
    {
        long long left, right;
        cin >> left >> right;

        if (left != -1)
        {
            tree[i].push_back(left);
            parent[left] = i;
        }

        if (right != -1)
        {
            tree[i].push_back(right);
            parent[right] = i;
        }
    }

    int count = 0;
    dfs(0, tree, colored, parent, count);
    cout << count;

    return 0;
}
