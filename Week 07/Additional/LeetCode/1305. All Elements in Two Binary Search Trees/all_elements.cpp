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

    void sorted(TreeNode* root, vector<int>& nodes)
    {
        if (!root)
        {
            return;
        }

        sorted(root->left, nodes);
        nodes.push_back(root->val);
        sorted(root->right, nodes);
    }

    vector<int> merge(vector<int>& left, vector<int>& right)
    {
        vector<int> res;

        int leftIdx = 0;
        int rightIdx = 0;

        while (leftIdx < left.size() && rightIdx < right.size())
        {
            if (left[leftIdx] <= right[rightIdx])
            {
                res.push_back(left[leftIdx++]);
            }

            else
            {
                res.push_back(right[rightIdx++]);
            }
        }

        while (leftIdx < left.size())
        {
            res.push_back(left[leftIdx++]);
        }

        while (rightIdx < right.size())
        {
            res.push_back(right[rightIdx++]);
        }

        return res;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> first;
        vector<int> second;

        sorted(root1, first);
        sorted(root2, second);

        return merge(first, second);
    }
};