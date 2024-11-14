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
    int rangeSumBST(TreeNode* root, int low, int high) {

        int sumOf = 0;
        if (!root)
        {
            return sumOf;
        }

        if (root->val >= low && root->val <= high)
        {
            sumOf = root->val;
        }

        return sumOf + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};