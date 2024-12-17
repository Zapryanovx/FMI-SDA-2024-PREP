/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    //(ptr to original, ptr to copy)
    unordered_map<Node*, Node*> indexToNode;

    Node* cloneGraph(Node* node) {
        if (!node)
        {
            return node;
        }

        auto iter = indexToNode.find(node);
        if (iter != indexToNode.end())
        {
            return iter->second;
        }

        Node* newNode = new Node(node->val);
        indexToNode[node] = newNode;

        for (auto neighbor : node->neighbors)
        {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return newNode;
    }
};