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

    int sum(TreeNode* curr, bool isLeft)
    {
        if (!curr)
        {
            return 0;
        }

        if (!curr->left && !curr->right)
        {
            if (isLeft)
            {
                return curr->val;
            }
        }

        return sum(curr->left, true) + sum(curr->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {

        return sum(root, false);
    }
};