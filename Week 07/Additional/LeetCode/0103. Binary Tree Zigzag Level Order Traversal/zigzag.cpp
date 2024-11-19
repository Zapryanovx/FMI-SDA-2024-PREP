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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
        {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        bool odd = false;

        while (!q.empty())
        {
            int currLevel = q.size();
            vector<int> level;
            for (int i = 0; i < currLevel; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                cout << node->val << endl;
                level.push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }

            if (level.size())
            {
                if (odd)
                {
                    reverse(level.begin(), level.end());
                }

                res.push_back(level);
            }

            odd = !odd;
        }

        return res;
    }
};