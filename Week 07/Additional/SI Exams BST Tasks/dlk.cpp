// https://www.hackerrank.com/contests/test4-sda-/challenges

void add(Node* root, vector<int>& nodes)
{
    if (!root)
    {
        return;
    }

    add(root->rightNode, nodes);
    add(root->leftNode, nodes);
    nodes.push_back(root->data);
}

void print(Node* root) {

    vector<int> nodes;
    add(root, nodes);

    for (size_t i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i];
        if (i + 1 != nodes.size())
        {
            cout << ';';
        }
    }
}