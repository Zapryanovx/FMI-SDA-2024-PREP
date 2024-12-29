#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST
{
    Node* root = nullptr;

    void printHelper(Node* curr)
    {
        if (!curr)
        {
            return;
        }

        cout << curr->val << " ";
        printHelper(curr->left);
        printHelper(curr->right);
    }

    Node* addHelper(Node* curr, int x)
    {
        if (!curr)
        {
            return new Node(x);
        }

        if (curr->val > x)
        {
            curr->left = addHelper(curr->left, x);
        }

        else if (curr->val < x)
        {
            curr->right = addHelper(curr->right, x);
        }

        return curr;
    }

public:
    BST() = default;
    BST(Node* root) : root(root) {}

    void print()
    {
        printHelper(this->root);
    }

    void add(int x)
    {
        this->root = addHelper(this->root, x);
    }

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BST* tree = new BST;

    int q;
    cin >> q;
    while (q--)
    {
        string command;
        cin >> command;

        int x;
        if (command == "add")
        {
            cin >> x;
            tree->add(x);
        }

        else
        {
            tree->print();
        }
    }
}
