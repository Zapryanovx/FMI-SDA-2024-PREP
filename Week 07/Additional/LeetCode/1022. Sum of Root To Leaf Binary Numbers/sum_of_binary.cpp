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

    void toBinary(TreeNode* root, vector<int>& converted, int curr)
    {
        if (!root)
        {
            return;
        }

        curr *= 2;
        curr += root->val;

        if (!root->left && !root->right)
        {
            converted.push_back(curr);
            return;
        }

        toBinary(root->left, converted, curr);
        toBinary(root->right, converted, curr);
    }


    int sumRootToLeaf(TreeNode* root) {

        vector<int> converted;
        toBinary(root, converted, 0);

        int sum = 0;
        for (auto& i : converted)
        {
            sum += i;
        }

        return sum;
    }
};