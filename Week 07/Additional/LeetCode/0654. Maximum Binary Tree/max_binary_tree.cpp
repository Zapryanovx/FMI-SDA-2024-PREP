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

    int findMax(vector<int>& nums, int left, int right)
    {
        auto maxIt = max_element(nums.begin() + left, nums.begin() + right);
        return distance(nums.begin(), maxIt);
    }

    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return nullptr;
        }

        int idxMax = findMax(nums, left, right);
        TreeNode* curr = new TreeNode(nums[idxMax]);
        curr->left = build(nums, left, idxMax);
        curr->right = build(nums, idxMax + 1, right);

        return curr;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return build(nums, 0, nums.size());
    }
};