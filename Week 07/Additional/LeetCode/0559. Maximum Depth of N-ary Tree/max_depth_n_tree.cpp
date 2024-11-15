/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    int dfs(Node* curr)
    {
        if (!curr)
        {
            return 0;
        }

        int depth = 0;
        for (auto* child : curr->children)
        {
            depth = max(depth, dfs(child));
        }

        return depth + 1;
    }

    int maxDepth(Node* root) {
        return dfs(root);
    }
};