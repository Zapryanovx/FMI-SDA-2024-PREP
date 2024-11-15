// https://www.hackerrank.com/contests/sda-2021-2021-test-3-november16/challenges/tree-specific-print

void preorderPrint(Node* curr, int dividedBy)
{
    if (!curr)
    {
        return;
    }

    if (!curr->left && !curr->right)
    {
        return;
    }

    if (curr->value % dividedBy == 0)
    {
        cout << curr->value << " ";
    }

    preorderPrint(curr->left, dividedBy);
    preorderPrint(curr->right, dividedBy);

}

void printSpecific(int dividedBy) {
    preorderPrint(root, dividedBy);
}