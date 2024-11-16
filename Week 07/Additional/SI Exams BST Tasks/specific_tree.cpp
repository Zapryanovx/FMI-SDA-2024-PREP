//https://www.hackerrank.com/contests/sda-2020-2021-test6-dbr8t-r/challenges/traversal-level-order
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB() {

        queue<Node*> q;
        q.push(root);

        int counter = 0;
        while (!q.empty())
        {
            int currLevel = q.size();
            vector<int> level;

            for (int i = 0; i < currLevel; i++)
            {
                level.push_back(q.front()->value);
                if (q.front()->left)
                {
                    q.push(q.front()->left);
                }

                if (q.front()->right)
                {
                    q.push(q.front()->right);
                }

                q.pop();
            }

            if (counter % 2 == 0)
            {
                for (int i = 0; i < level.size(); i++)
                {
                    cout << level[i] << " ";
                }
            }

            else
            {
                for (int i = level.size() - 1; i >= 0; i--)
                {
                    cout << level[i] << " ";
                }
            }

            counter++;
        }
    }

private:
    //you can write helper functions if needed
    Node* root;

    Node* insert(Node* curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        }
        else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        }
        else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }

    tree.printSFB();
    return 0;
}