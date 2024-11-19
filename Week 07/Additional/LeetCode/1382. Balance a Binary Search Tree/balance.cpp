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

    void inorder(TreeNode* node, vector<int>& sortedValues)
    {
        if (!node)
        {
            return;
        }

        inorder(node->left, sortedValues);
        sortedValues.push_back(node->val);
        inorder(node->right, sortedValues);
    }

    TreeNode* build(vector<int>& sortedValues, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(sortedValues[mid]);
        node->left = build(sortedValues, left, mid - 1);
        node->right = build(sortedValues, mid + 1, right);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> sortedValues;
        inorder(root, sortedValues);

        return build(sortedValues, 0, sortedValues.size() - 1);
    }
};