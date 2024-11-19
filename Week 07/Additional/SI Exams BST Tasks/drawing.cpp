// https://www.hackerrank.com/contests/sda-hw-6-2023/challenges/task3score/copy-from/1385557101

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node
{
    long long val = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node() = default;
    Node(int val) : val(val) {}
};

long long getNodesCount(Node* curr)
{
    if (!curr)
    {
        return 0;
    }

    return 1 + getNodesCount(curr->left) + getNodesCount(curr->right);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    Node* arr[1000000 + 1]{};
    for (long long i = 0; i < n; i++)
    {
        long long left, right;
        cin >> left >> right;

        if (!arr[i])
        {
            arr[i] = new Node(i);
        }

        if (left != -1)
        {
            if (!arr[left])
            {
                arr[left] = new Node(left);
            }

            arr[i]->left = arr[left];
        }

        if (right != -1)
        {
            if (!arr[right])
            {
                arr[right] = new Node(right);
            }

            arr[i]->right = arr[right];
        }
    }

    long long product = LLONG_MIN;
    for (long long i = 0; i < n; i++)
    {
        long long left = getNodesCount(arr[i]->left);
        long long right = getNodesCount(arr[i]->right);
        long long mid = n - left - right - 1;

        if (left == 0)
        {
            left = 1;
        }

        if (right == 0)
        {
            right = 1;
        }

        if (mid == 0)
        {
            mid = 1;
        }

        product = max(product, left * right * mid);
    }

    cout << product;

    return 0;
}