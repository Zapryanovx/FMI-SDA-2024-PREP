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

    int maxDepth(TreeNode* root, int counter)
    {
        if (!root)
        {
            return counter;
        }

        return max(maxDepth(root->left, counter + 1), maxDepth(root->right, counter + 1));
    }

    int maxDepth(TreeNode* root) {

        if (!root)
        {
            return 0;
        }

        int counter = 0;
        return maxDepth(root, counter);
    }
};