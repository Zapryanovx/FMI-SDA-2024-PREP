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

    void dfs(TreeNode* node, vector<TreeNode*>& v)
    {
        if (!node)
        {
            return;
        }

        dfs(node->left, v);
        v.push_back(node);
        dfs(node->right, v);
    }

    TreeNode* increasingBST(TreeNode* root) {

        vector<TreeNode*> v;
        dfs(root, v);

        TreeNode* start = v[0];
        start->left = nullptr;
        start->right = nullptr;

        TreeNode* curr = start;
        for (int i = 1; i < v.size(); i++)
        {
            v[i]->left = nullptr;
            v[i]->right = nullptr;

            curr->right = v[i];
            curr = curr->right;
        }

        return start;
    }
};