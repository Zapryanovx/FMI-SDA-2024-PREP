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

    void inorderTransversal(TreeNode* p, vector<int>& res)
    {
        if (!p)
        {
            return;
        }

        inorderTransversal(p->left, res);
        res.push_back(p->val);
        inorderTransversal(p->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        if (!root)
        {
            return {};
        }

        vector<int> res;
        inorderTransversal(root, res);

        return res;
    }
};