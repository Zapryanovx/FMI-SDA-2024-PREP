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

    void convertBST(TreeNode* node, int& sum)
    {
        if (!node)
        {
            return;
        }

        convertBST(node->right, sum);
        sum += node->val;
        node->val = sum;
        convertBST(node->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }

        int sum = 0;
        convertBST(root, sum);
        return root;
    }
};