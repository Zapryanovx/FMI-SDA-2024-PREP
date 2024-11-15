// https://www.hackerrank.com/contests/sda-2021-2021-test-3-november16/challenges/challenge-1692

int sum(Node* root)
{
    if (!root)
    {
        return 0;
    }

    if (!root->leftNode && !root->rightNode)
    {
        if (root->data % 2 != 0)
        {
            return root->data;
        }
        return 0;
    }

    return sum(root->leftNode) + sum(root->rightNode);
}

void leaves(Node* root) {

    int res = sum(root);
    cout << res << endl;
}
