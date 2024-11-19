/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* node, int sum, int& res)
    {
        if (!node)
        {
            return;
        }

        sum *= 10;
        sum += node->val;

        if (!node->left && !node->right)
        {
            res += sum;
            return;
        }

        dfs(node->left, sum, res);
        dfs(node->right, sum, res);

    }

    int sumNumbers(TreeNode* root) {

        int sum = 0, res = 0;
        dfs(root, sum, res);
        return res;
    }
};