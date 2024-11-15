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

    void preorderTraversal(TreeNode* p, vector<int>& res)
    {
        if (!p)
        {
            return;
        }

        res.push_back(p->val);
        preorderTraversal(p->left, res);
        preorderTraversal(p->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
        {
            return {};
        }

        vector<int> res;
        preorderTraversal(root, res);

        return res;
    }
};