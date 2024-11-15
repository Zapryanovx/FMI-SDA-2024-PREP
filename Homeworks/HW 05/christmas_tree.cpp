#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode
{
    long long val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode() = default;
    TreeNode(long long val) : val(val) {}
};

bool isValidBST(TreeNode* curr, long long lower, long long upper)
{
    if (!curr)
    {
        return true;
    }

    if (lower >= curr->val || upper <= curr->val)
    {
        return false;
    }

    return isValidBST(curr->left, lower, curr->val)
        && isValidBST(curr->right, curr->val, upper);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    for (long long i = 0; i < t; ++i)
    {
        long long n;
        cin >> n;

        vector<TreeNode*> tree(n);
        for (long long j = 0; j < n; ++j)
        {
            int val, left, right;
            cin >> val >> left >> right;

            if (!tree[j])
            {
                tree[j] = new TreeNode(val);
            }

            else
            {
                tree[j]->val = val;
            }

            if (left != -1)
            {
                tree[left] = new TreeNode();
                tree[j]->left = tree[left];
            }

            if (right != -1)
            {
                tree[right] = new TreeNode();
                tree[j]->right = tree[right];
            }
        }

        bool res = isValidBST(tree[0], LLONG_MIN, LLONG_MAX);
        cout << res << endl;
    }


    return 0;
}