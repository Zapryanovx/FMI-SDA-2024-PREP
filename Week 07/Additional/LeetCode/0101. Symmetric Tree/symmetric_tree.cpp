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
    bool checkSymmetry(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
        {
            return true;
        }

        if (!p || !q)
        {
            return false;
        }

        return p->val == q->val && checkSymmetry(p->left, q->right) && checkSymmetry(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {

        if (!root)
        {
            return true;
        }

        return checkSymmetry(root->left, root->right);
    }
};