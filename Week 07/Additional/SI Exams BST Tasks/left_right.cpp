// https://www.hackerrank.com/contests/test4-sda-/challenges/left-right-2

void counter(Node* root, int& leftCounter, int& rightCounter)
{
    if (!root->leftNode && !root->rightNode)
    {
        return;
    }

    if (root->leftNode)
    {
        leftCounter++;
        counter(root->leftNode, leftCounter, rightCounter);
    }

    if (root->rightNode)
    {
        rightCounter++;
        counter(root->rightNode, leftCounter, rightCounter);
    }
}

void leftRight(Node* root) {

    int leftCounter = 0, rightCounter = 0;
    counter(root, leftCounter, rightCounter);

    cout << "[" << leftCounter << "," << rightCounter << "]" << endl;
}