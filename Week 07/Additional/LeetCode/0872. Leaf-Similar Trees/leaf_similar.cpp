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

    void addLeaves(TreeNode* root, vector<int>& leaves)
    {
        if (!root)
        {
            return;
        }

        if (!root->left && !root->right)
        {
            leaves.push_back(root->val);
        }

        addLeaves(root->left, leaves);
        addLeaves(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> root1Leaves;
        vector<int> root2Leaves;

        addLeaves(root1, root1Leaves);
        addLeaves(root2, root2Leaves);

        if (root1Leaves.size() != root2Leaves.size())
        {
            return false;
        }

        for (int i = 0; i < root1Leaves.size(); i++)
        {
            if (root1Leaves[i] != root2Leaves[i])
            {
                return false;
            }
        }

        return true;
    }
};