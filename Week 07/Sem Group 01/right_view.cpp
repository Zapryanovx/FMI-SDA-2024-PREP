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

    void rightSideView(TreeNode* p, vector<int>& res)
    {
        if (!p)
        {
            return;
        }

        queue<TreeNode*> q;
        q.push(p);

        while (!q.empty())
        {
            int level = q.size();

            for (int i = 0; i < level; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                //last node of level 
                if (i == level - 1)
                {
                    res.push_back(curr->val);
                }

                if (curr->left)
                {
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if (!root)
        {
            return {};
        }

        vector<int> res;
        rightSideView(root, res);

        return res;
    }
};