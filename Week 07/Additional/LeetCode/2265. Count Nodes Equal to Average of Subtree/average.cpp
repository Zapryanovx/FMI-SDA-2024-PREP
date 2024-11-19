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

    void dfs(TreeNode* node, int& sum, int& nodes, int& counter)
    {
        if (!node)
        {
            return;
        }

        int leftSum = 0, leftNodes = 0;
        int rightSum = 0, rightNodes = 0;

        dfs(node->left, leftSum, leftNodes, counter);
        dfs(node->right, rightSum, rightNodes, counter);

        sum += leftSum + rightSum + node->val;
        nodes += leftNodes + rightNodes + 1;

        if (sum / nodes == node->val)
        {
            counter++;
        }

    }

    int averageOfSubtree(TreeNode* root) {
        int counter = 0, sum = 0, nodes = 0;
        dfs(root, sum, nodes, counter);
        return counter;
    }
};