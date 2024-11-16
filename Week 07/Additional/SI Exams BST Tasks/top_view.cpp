// https://www.hackerrank.com/contests/sda-hw-6/challenges/tree-top-view/copy-from/1385477978
void topView(Node* root) {

    queue<pair<Node*, int>> q;
    q.push({ root, 0 });

    map<int, int> mp;
    while (!q.empty())
    {
        int level = q.size();

        for (int i = 0; i < level; i++)
        {
            pair<Node*, int> p = q.front();
            q.pop();

            if (!mp[p.second])
            {
                mp[p.second] = p.first->data;
            }

            if (p.first->left)
            {
                q.push({ p.first->left, p.second - 1 });
            }

            if (p.first->right)
            {
                q.push({ p.first->right, p.second + 1 });
            }
        }
    }

    for (auto& pair : mp)
    {
        cout << pair.second << " ";
    }

}