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

    int minDepth(TreeNode* p, int depth)
    {
        if (!p)
        {
            return INT_MAX;
        }

        if (!p->left && !p->right)
        {
            return depth + 1;
        }

        return min(minDepth(p->left, depth + 1), minDepth(p->right, depth + 1));
    }

    int minDepth(TreeNode* root) {

        if (!root)
        {
            return 0;
        }

        return minDepth(root, 0);
    }
};