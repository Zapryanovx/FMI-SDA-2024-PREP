#include <bits/stdc++.h>
using namespace std;

constexpr long long MAX_SIZE = 1000000 + 1;
long long in[MAX_SIZE]{};
long long out[MAX_SIZE]{};
long long timer = 0;

struct TreeNode
{
    long long val = 0;
    vector<TreeNode*> children;

    TreeNode(long long val) : val(val)
    {}
};

void dfs(TreeNode* curr)
{
    if (!curr)
    {
        return;
    }

    in[curr->val] = timer++;
    for (long long i = 0; i < curr->children.size(); i++)
    {
        dfs(curr->children[i]);
    }
    out[curr->val] = timer++;

    return;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<TreeNode*> tree(MAX_SIZE);
    for (long long i = 0; i < N - 1; ++i)
    {
        long long parent, child;
        cin >> parent >> child;

        if (!tree[parent])
        {
            tree[parent] = new TreeNode(parent);
        }

        if (!tree[child])
        {
            tree[child] = new TreeNode(child);
        }

        tree[parent]->children.push_back(tree[child]);
    }

    dfs(tree[0]);

    long long Q;
    cin >> Q;

    for (long long i = 0; i < Q; ++i)
    {
        long long potParent, potChild;
        cin >> potParent >> potChild;

        if (in[potParent] <= in[potChild] && out[potParent] >= out[potChild])
        {
            printf("%s\n", "YES");
        }

        else
        {
            printf("%s\n", "NO");
        }
    }


    return 0;
}
