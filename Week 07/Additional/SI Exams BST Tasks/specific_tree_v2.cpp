// https://www.hackerrank.com/contests/sda-test3-2022-2023-rdsafgtvh/challenges/--149/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node() = default;
    Node(int val) : val(val) {}
};

Node* insert(Node* root, int val)
{
    if (!root)
    {
        return new Node(val);
    }

    if (root->val > val)
    {
        root->left = insert(root->left, val);
    }

    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void findNodes(Node* root, vector<int>& res)
{
    if (!root)
    {
        return;
    }

    if (root->left && root->right)
    {
        res.push_back(root->val);
    }

    findNodes(root->left, res);
    findNodes(root->right, res);

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        Node* root = nullptr;
        for (int i = 0; i < n; i++)
        {
            int node;
            cin >> node;
            root = insert(root, node);
        }

        vector<int> res;
        findNodes(root, res);

        if (res.size())
        {
            for (int i = 0; i < res.size(); i++)
            {
                cout << res[i] << " ";
            }
        }
        cout << endl;

    }
    return 0;
}
