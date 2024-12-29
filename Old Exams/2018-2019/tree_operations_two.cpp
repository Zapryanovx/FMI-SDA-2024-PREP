#include <bits/stdc++.h>
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

    Node* removeHelper(Node* curr, int x)
    {
        if (!curr)
        {
            return curr;
        }

        if (curr->val > x)
        {
            curr->left = removeHelper(curr->left, x);
        }

        else if (curr->val < x)
        {
            curr->right = removeHelper(curr->right, x);
        }
        else
        {
            if (!curr->left && !curr->right)
            {
                return nullptr;
            }

            if (!curr->left)
            {
                return curr->right;
            }

            if (!curr->right)
            {
                return curr->left;
            }

            auto iter = curr->right;
            while (iter->left)
            {
                iter = iter->left;
            }
            swap(curr->val, iter->val);
            curr->right = removeHelper(curr->right, iter->val);
        }

        return curr;
    }


    void printOddHelper(Node* curr)
    {
        if (!curr)
        {
            return;
        }

        queue<Node*> q;
        q.push(curr);
        int layer = 1;

        while (!q.empty())
        {
            int level = q.size();
            for (int i = 0; i < level; i++)
            {
                auto curr = q.front();
                q.pop();

                if (layer % 2 == 1)
                {
                    cout << curr->val << " ";
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

            layer++;
        }
    }

    void printHelper(Node* curr)
    {
        if (!curr)
        {
            return;
        }

        cout << curr->val << " ";
        printHelper(curr->left);
        printHelper(curr->right);#include <cmath>
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

    Node(int x): val(x), left(nullptr), right(nullptr){}
};

class BST
{
    Node* root = nullptr;
    
    void printHelper(Node* curr)
    {
        if(!curr)
        {
            return;
        }
        
        cout << curr->val << " ";
        printHelper(curr->left);
        printHelper(curr->right);
    }
    
    Node* addHelper(Node* curr, int x)
    {
        if(!curr)
        {
            return new Node(x);
        }
        
        if(curr->val > x)
        {
            curr->left = addHelper(curr->left, x);
        }
        
        else if(curr->val < x)
        {
            curr->right = addHelper(curr->right, x);
        }
        
        return curr;
    }
    
    public:
    BST() = default;
    BST(Node* root): root(root){}
    
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
    while(q--)
    {
        string command;
        cin >> command;
        
        int x;
        if(command == "add")
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

    }

public:
    BST() = default;
    BST(Node* root) : root(root) {}

    void add(int x)
    {
        this->root = addHelper(this->root, x);
    }

    void remove(int x)
    {
        this->root = removeHelper(this->root, x);
    }

    void print_odd_layers()
    {
        printOddHelper(this->root);
    }


    void print()
    {
        printHelper(this->root);
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

        else if (command == "remove")
        {
            cin >> x;
            tree->remove(x);
        }

        else if (command == "print_odd_layers")
        {
            tree->print_odd_layers();
        }

        else
        {
            tree->print();
        }
    }
}
