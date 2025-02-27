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

    void dfs(TreeNode* root, int targetSum, int sum, vector<int>& path, vector<vector<int>>& res)
    {
        if (!root)
        {
            return;
        }

        sum += root->val;
        path.push_back(root->val);

        if (!root->left && !root->right && targetSum == sum)
        {
            res.push_back(path);
        }

        dfs(root->left, targetSum, sum, path, res);
        dfs(root->right, targetSum, sum, path, res);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, 0, path, res);

        return res;
    }
};