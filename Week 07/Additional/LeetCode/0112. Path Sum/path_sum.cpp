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

    int sumPath(TreeNode* p, int sum, int target)
    {
        if (!p)
        {
            return false;
        }

        if (!p->left && !p->right)
        {
            return sum + p->val == target;
        }

        return sumPath(p->left, sum + p->val, target) || sumPath(p->right, sum + p->val, target);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        if (!root)
        {
            return false;
        }

        return sumPath(root, 0, targetSum);
    }
};