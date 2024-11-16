//https://www.hackerrank.com/contests/kontrolno-3/challenges

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    long long val = 0;
    vector<Node*> children;
    Node(long long val) : val(val)
    {}
};


void dfs(Node* node, vector<int>& res)
{
    if (!node)
    {
        return;
    }

    for (int i = 0; i < node->children.size(); i++)
    {
        res[node->val]++;
        dfs(node->children[i], res);
        res[node->val] += res[node->children[i]->val];
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Node*> tree(n);
    for (int i = 0; i < n - 1; i++)
    {
        int p, c;
        cin >> p >> c;

        if (!tree[p])
        {
            tree[p] = new Node(p);
        }

        if (!tree[c])
        {
            tree[c] = new Node(c);
        }

        tree[p]->children.push_back(tree[c]);
    }

    vector<int> res(n);
    dfs(tree[0], res);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }


    return 0;
}
