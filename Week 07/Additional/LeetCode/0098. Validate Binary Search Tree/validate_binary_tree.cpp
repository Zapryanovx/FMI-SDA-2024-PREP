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
    bool isValidBST(TreeNode* root, long long lower, long long upper) {

        if (!root)
        {
            return true;
        }

        if (lower >= root->val || upper <= root->val)
        {
            return false;
        }

        return isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root)
    {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};